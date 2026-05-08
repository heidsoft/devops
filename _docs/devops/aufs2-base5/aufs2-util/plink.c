/*
 * Copyright (C) 2005-2009 Junjiro Okajima
 *
 * This program, aufs is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#define _FILE_OFFSET_BITS	64	/* ftw.h */
#define _XOPEN_SOURCE		500	/* ftw.h */
#define _GNU_SOURCE			/* ftw.h */

#include <sys/ioctl.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <dirent.h>
#include <ftw.h>
#include <mntent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <linux/aufs_type.h>
#include "au_util.h"

/* todo: try argz? */
static struct name_array {
	char *o;
	int bytes;

	char *cur;
	int nname;
} na;

static struct ino_array {
	char *o;
	int bytes;

	union {
		char *p;
		ino_t *cur;
	};
	int nino;
} ia;

static int na_append(char *plink_dir, char *name)
{
	int l, sz;
	char *p;
	const int cur = na.cur - na.o;

	l = strlen(plink_dir) + strlen(name) + 2;
	sz = na.bytes + l;
	p = realloc(na.o, sz);
	if (!p)
		AuFin("realloc");

	na.o = p;
	na.bytes = sz;
	na.cur = p + cur;
	na.cur += sprintf(na.cur, "%s/%s", plink_dir, name) + 1;
	na.nname++;

	return 0;
}

static int ia_append(ino_t ino)
{
	int sz;
	char *p;
	const int cur = ia.p - ia.o;

	sz = na.bytes + sizeof(ino_t);
	p = realloc(ia.o, sz);
	if (!p)
		AuFin("realloc");

	ia.o = p;
	ia.bytes = sz;
	ia.p = p + cur;
	*ia.cur++ = ino;
	ia.nino++;

	return 0;
}

static int build_array(char *plink_dir)
{
	int err;
	DIR *dp;
	struct dirent *de;
	char *p;
	ino_t ino;

	err = access(plink_dir, F_OK);
	if (err)
		return 0;

	err = 0;
	dp = opendir(plink_dir);
	if (!dp)
		AuFin(plink_dir);
	while ((de = readdir(dp))) {
		if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, ".."))
			continue;
#if 0
		if (de->d_type == DT_DIR) {
			errno = EISDIR;
			AuFin(de->d_name);
		}
#endif

		err = na_append(plink_dir, de->d_name);
		if (err)
			break;

		p = strchr(de->d_name, '.');
		if (!p) {
			errno = EINVAL;
			AuFin("internal error, %s", de->d_name);
		}
		*p = 0;
		errno = 0;
		ino = strtoull(de->d_name, NULL, 0);
		if (ino == /*ULLONG_MAX*/-1 && errno == ERANGE)
			AuFin("internal error, %s", de->d_name);
		err = ia_append(ino);
		if (err)
			break;
	}
	closedir(dp);

	return err;
}

static int ia_test(ino_t ino)
{
	int i;
	ino_t *p;

	/* todo: hash table */
	ia.p = ia.o;
	p = ia.cur;
	for (i = 0; i < ia.nino; i++)
		if (*p++ == ino)
			return 1;
	return 0;
}

/* ---------------------------------------------------------------------- */

static int ftw_list(const char *fname, const struct stat *st, int flags,
		   struct FTW *ftw)
{
	if (!strcmp(fname + ftw->base, AUFS_WH_PLINKDIR))
		return FTW_SKIP_SUBTREE;
	if (flags == FTW_D || flags == FTW_DNR)
		return FTW_CONTINUE;

	if (ia_test(st->st_ino))
		puts(fname);

	return FTW_CONTINUE;
}

static int ftw_cpup(const char *fname, const struct stat *st, int flags,
		   struct FTW *ftw)
{
	int err;

	if (!strcmp(fname + ftw->base, AUFS_WH_PLINKDIR))
		return FTW_SKIP_SUBTREE;
	if (flags == FTW_D || flags == FTW_DNR)
		return FTW_CONTINUE;

	/*
	 * do nothing but update something harmless in order to make it copyup
	 */
	if (ia_test(st->st_ino)) {
		Dpri("%s\n", fname);
		if (!S_ISLNK(st->st_mode))
			err = chown(fname, -1, -1);
		else
			err = lchown(fname, -1, -1);
		if (err)
			AuFin(fname);
	}

	return FTW_CONTINUE;
}

/* ---------------------------------------------------------------------- */

static DIR *dp;
void au_plink_maint(char *path)
{
	int err;

	if (path) {
		if (dp) {
			errno = EINVAL;
			AuFin("dp is not NULL");
		}
		dp = opendir(path);
		if (!dp)
			AuFin(path);

		err = ioctl(dirfd(dp), AUFS_CTL_PLINK_MAINT);
#ifndef DEBUG
		if (err)
			AuFin("AUFS_CTL_PLINK_MAINT");
#endif
	} else {
		err = closedir(dp);
		if (err)
			AuFin("closedir");
		dp = NULL;
	}
}

void au_clean_plink(void)
{
	int err;

	err = ioctl(dirfd(dp), AUFS_CTL_PLINK_CLEAN);
#ifndef DEBUG
	if (err)
		AuFin("AUFS_CTL_PLINK_CLEAN");
#endif
}

static int do_plink(char *cwd, int cmd, int nbr, char *br[])
{
	int err, i, l;
	struct rlimit rlim;
	__nftw_func_t func;
	char *p;

	err = 0;
	switch (cmd) {
	case AuPlink_FLUSH:
		/*FALLTHROUGH*/
	case AuPlink_CPUP:
		func = ftw_cpup;
		break;
	case AuPlink_LIST:
		func = ftw_list;
		break;
	default:
		errno = EINVAL;
		AuFin(NULL);
		func = NULL; /* never reach here */
	}

	for (i = 0; i < nbr; i++) {
		//puts(br[i]);
		p = strchr(br[i], '=');
		if (strcmp(p + 1, AUFS_BRPERM_RW)
		    && strcmp(p + 1, AUFS_BRPERM_RWNLWH))
			continue;

		*p = 0;
		l = strlen(br[i]);
		p = malloc(l + sizeof(AUFS_WH_PLINKDIR) + 2);
		if (!p)
			AuFin("malloc");
		sprintf(p, "%s/%s", br[i], AUFS_WH_PLINKDIR);
		//puts(p);
		err = build_array(p);
		if (err)
			AuFin("build_array");
		free(p);
	}
	if (!ia.nino)
		goto out;

	if (cmd == AuPlink_LIST) {
		ia.p = ia.o;
		for (i = 0; i < ia.nino; i++)
			printf("%llu ", *ia.cur++);
		putchar('\n');
	}

	err = getrlimit(RLIMIT_NOFILE, &rlim);
	if (err)
		AuFin("getrlimit");
	nftw(cwd, func, rlim.rlim_cur - 10,
	     FTW_PHYS | FTW_MOUNT | FTW_ACTIONRETVAL);
	/* ignore */

	if (cmd == AuPlink_FLUSH) {
		au_clean_plink();

		na.cur = na.o;
		for (i = 0; i < na.nname; i++) {
			Dpri("%s\n", na.cur);
			err = unlink(na.cur);
			if (err)
				AuFin(na.cur);
			na.cur += strlen(na.cur) + 1;
		}
	}

 out:
	free(ia.o);
	free(na.o);
	return err;
}

int au_plink(char cwd[], int cmd, int begin_maint, int end_maint)
{
	int err, nbr;
	struct mntent ent;
	char **br;

	if (begin_maint)
		au_plink_maint(cwd);

	err = au_proc_getmntent(cwd, &ent);
	if (err)
		AuFin("no such mount point");

	if (hasmntopt(&ent, "noplink"))
		goto out; /* success */

#ifdef DEBUG
	//char a[] = "a,b,br:/tmp/br0=rw:/br1=ro";
	char a[] = "a,b,si=1,c";
	ent.mnt_opts = a;
#endif
	err = au_br(&br, &nbr, &ent);
	//printf("nbr %d\n", nbr);
	if (err)
		AuFin(NULL);

	err = do_plink(cwd, cmd, nbr, br);
	if (err)
		AuFin(NULL);

 out:
	if (end_maint)
		au_plink_maint(NULL);
	return err;
}
