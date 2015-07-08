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

/* cf. fstab.c or the locking for /etc/mtab in util-linux */
/*
 * we need to extract a part of util-linux and create a simple and generic
 * library for locking /etc/mtab.
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <mntent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "au_util.h"

void au_print_ent(struct mntent *ent)
{
	printf("%s on %s type %s (%s)\n",
	       ent->mnt_fsname, ent->mnt_dir, ent->mnt_type, ent->mnt_opts);
}

/* ---------------------------------------------------------------------- */

static void lock_mtab(char *pid_file)
{
	int err, i;

	for (i = 0; i < 5; i++) {
		err = link(pid_file, MTab "~");
		if (!err)
			break;
		sleep(1);
	}
	if (err)
		AuFin(MTab "~");
}

static void unlock_mtab(void)
{
	int err;

	err = rename(MTab "~", MTab);
	if (err)
		AuFin(MTab);
}

static void append_mtab(FILE *fp, FILE *ofp, struct mntent *ent)
{
	int err;
	struct mntent *p;

	while ((p = getmntent(ofp))) {
		err = addmntent(fp, p);
		if (err)
			AuFin("addmntent");
	}

	err = addmntent(fp, ent);
	if (err)
		AuFin("addmntent");
}

/* todo: there are some cases which options are not changed */
static void update_mtab(FILE *fp, char *mntpnt, int do_remount, int do_verbose)
{
	int err;
	long pos;
	FILE *ofp;
	struct mntent ent, *p;

	/* prohibit updating mount options for this mntpnt */
	au_plink_maint(mntpnt);
	err = au_proc_getmntent(mntpnt, &ent);
	if (err)
		AuFin("no such mount point");

	ofp = setmntent(MTab, "r");
	if (!ofp)
		AuFin(MTab);

	if (do_remount) {
		/* find the last one */
		pos = -1;
		while ((p = getmntent(ofp))) {
			if (!strcmp(p->mnt_dir, mntpnt))
				pos = ftell(ofp);
		}
		rewind(ofp);

		if (pos > 0) {
			while ((p = getmntent(ofp))) {
				if (ftell(ofp) == pos) {
					/* replace the line */
					p = &ent;
					pos = -1;
				}
				err = addmntent(fp, p);
				if (err)
					AuFin("addmntent");
			}
			if (pos > 0)
				AuFin("internal error");
		} else
			append_mtab(fp, ofp, &ent);
	} else
		append_mtab(fp, ofp, &ent);

	endmntent(ofp); /* ignore */
	au_plink_maint(NULL);
	if (do_verbose)
		au_print_ent(&ent);
}

/* ---------------------------------------------------------------------- */

int au_update_mtab(char *mntpnt, int do_remount, int do_verbose)
{
	int err, fd, status, e2;
	pid_t pid;
	ino_t ino;
	struct stat st;
	struct flock flock = {
		.l_type		= F_WRLCK,
		.l_whence	= SEEK_SET,
		.l_start	= 0,
		.l_len		= 0
	};
	char pid_file[sizeof(MTab "~.") + 20];
	FILE *fp;

#if 0
	err = lstat(MTab, &st);
	if (S_ISLNK(st.st_mode))
		return 0;
#endif

	snprintf(pid_file, sizeof(pid_file), MTab "~.%d", getpid());
	fd = open(pid_file, O_RDWR | O_CREAT | O_EXCL,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		AuFin(pid_file);
	err = fcntl(fd, F_SETLK, &flock);
	if (err)
		AuFin(pid_file);
	fp = fdopen(fd, "r+");
	if (!fp)
		AuFin(pid_file);

	pid = fork();
	if (!pid) {
		lock_mtab(pid_file);
		update_mtab(fp, mntpnt, do_remount, do_verbose);
		unlock_mtab();
		return 0;
	} else if (pid < 0)
		AuFin("fork");

	err = fstat(fd, &st);
	if (err)
		perror(pid_file);
	ino = st.st_ino;

	err = waitpid(pid, &status, 0);
	if (err < 0) {
		perror(pid_file);
		goto out;
	}
	err = !WIFEXITED(status);
	if (!err)
		err = WEXITSTATUS(status);

	e2 = unlink(pid_file);
	if (e2 && errno != ENOENT)
		perror(pid_file);
	e2 = stat(MTab "~", &st);
	if (!e2) {
		if (st.st_ino == ino) {
			/*
			 * The inode number is same,
			 * it means it is we who made the file.
			 * If someone else removed our file between stat(2) and
			 * unlink(2), it is a breakage of the rule.
			 */
			e2 = unlink(MTab "~");
			if (e2)
				perror(MTab);
		}
	} else if (errno != ENOENT)
		perror(MTab "~");
	fclose(fp);

 out:
	return err;
}
