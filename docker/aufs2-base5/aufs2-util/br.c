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

#define _GNU_SOURCE /* strndup */

#include <sys/stat.h>
#include <sys/types.h>
#include <mntent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <linux/aufs_type.h>
#include "au_util.h"

static int by_opts(char ***br, int *nbr, char *bropt)
{
	char *p, **a;
	int l;

	/* bropts is placed at the end of mnt_opts */
	errno = EINVAL;
	//puts(bropt);
	if (strchr(bropt, ','))
		AuFin(bropt);

	l = strlen(bropt);
	p = malloc(l + 2);
	if (!p)
		AuFin("malloc");
	memcpy(p, bropt, l + 1);
	bropt = p;
	bropt[l + 1] = 0; /* end marker */

	*nbr = 1;
	while (1) {
		p = strchr(p + 1, ':');
		if (!p)
			break;
		*p = 0;
		(*nbr)++;
	}

	a = malloc(sizeof(a) * (*nbr + 1));
	if (!a)
		AuFin("malloc");

	*br = a;
	*a++ = bropt;
	p = bropt;
	while (*p) {
		p += strlen(p) + 1;
		*a++ = p;
	}
	*--a = NULL;
	/* don't free bropt */

	return 0;
}

#ifdef DEBUG
#define SiPathPrefix	"/tmp/aufs/si_"
#define BufSiz		4
#else
#define SiPathPrefix	"/sys/fs/aufs/si_"
#define BufSiz		BUFSIZ
#endif

static int by_sysfs(char ***br, int *nbr, char *siopt)
{
	int err, i, l, sz;
	char buf[BufSiz], path[] = SiPathPrefix "1234567890123456/br32767";
	char *p, *end, **a, *q;
	FILE *fp;

	errno = EINVAL;
	end = strchr(siopt, ',');
	if (end)
		i = end - siopt;
	else
		i = strlen(siopt);

	strncpy(path + sizeof(SiPathPrefix) - 1, siopt, i);
	p = path + sizeof(SiPathPrefix) - 1 + i;
	strcpy(p, "/br");
	p += 3; /* "/br" */
	*nbr = 0;
	err = 0;
	while (!err) {
		sprintf(p, "%d", (*nbr)++);
		err = access(path, F_OK);
	}

	a = malloc(sizeof(*br) * *nbr);
	if (!a)
		AuFin("malloc");

	(*nbr)--;
	*br = a;
	for (i = 0; i < *nbr; i++) {
		sprintf(p, "%d", i);
		fp = fopen(path, "r");
		if (!fp)
			AuFin(path);
		if (fgets(buf, sizeof(buf), fp) != buf)
			AuFin(path);
		l = strlen(buf);
		if (l < 1)
			AuFin("internal error, %d", l);

		q = strndup(buf, l - 1);
		if (buf[l - 1] != '\n') {
			/* a branch path with crazy length */
			/* stat(2) for sysfs is meaningless */
			sz = sizeof(buf);
			do {
				free(q);
				sz <<= 1;
				q = malloc(sz);
				if (!q)
					AuFin("malloc");
				rewind(fp);
				if (fgets(q, sz, fp) != q)
					AuFin(path);
				l = strlen(q);
			} while (q[l - 1] != '\n');
			q[l - 1] = 0;
		}

		*a++ = q;
		/* don't free q */
		fclose(fp); /* ignore */
	}
	*a = NULL;

	return 0;
}

#define BrOpt	"br:"
#define SiOpt	"si="
int au_br(char ***br, int *nbr, struct mntent *ent)
{
	char *p;

	*nbr = 0;
	p = hasmntopt(ent, BrOpt);
	if (p)
		return by_opts(br, nbr, p + sizeof(BrOpt) - 1);
	p = hasmntopt(ent, SiOpt);
	if (p)
		return by_sysfs(br, nbr, p + sizeof(SiOpt) - 1);

	/* broken opts */
	AuFin("internal error, %s", ent->mnt_opts);
	return -1; /* never reach here */
}
