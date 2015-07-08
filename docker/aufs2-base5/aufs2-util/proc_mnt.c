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

#include <sys/types.h>
#include <errno.h>
#include <mntent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "au_util.h"

#define ProcMounts "/proc/self/mounts"

static void copy_ent(struct mntent *dst, struct mntent *src)
{
	free(dst->mnt_opts);
	free(dst->mnt_type);
	free(dst->mnt_dir);
	free(dst->mnt_fsname);

	dst->mnt_dir = NULL;
	dst->mnt_type = NULL;
	dst->mnt_opts = NULL;

	dst->mnt_fsname = strdup(src->mnt_fsname);
	if (dst->mnt_fsname)
		dst->mnt_dir = strdup(src->mnt_dir);
	if (dst->mnt_dir)
		dst->mnt_type = strdup(src->mnt_type);
	if (dst->mnt_type)
		dst->mnt_opts = strdup(src->mnt_opts);
	if (dst->mnt_opts) {
		dst->mnt_freq = src->mnt_freq;
		dst->mnt_passno = src->mnt_passno;
	} else
		AuFin("strdup");

}

int au_proc_getmntent(char *mntpnt, struct mntent *rent)
{
	int found;
	struct mntent *p;
	FILE *fp;

	fp = setmntent(ProcMounts, "r");
	if (!fp)
		AuFin(ProcMounts);

	/* find the last one */
	memset(rent, 0, sizeof(*rent));
	found = 0;
	while ((p = getmntent(fp)))
		if (!strcmp(p->mnt_dir, mntpnt)) {
			Dpri("%s, %s, %s, %s, %d, %d\n",
			     p->mnt_fsname, p->mnt_dir, p->mnt_type,
			     p->mnt_opts, p->mnt_freq, p->mnt_passno);
			copy_ent(rent, p);
			found = 1;
		}
	endmntent(fp);

	if (!found) {
		errno = EINVAL;
		AuFin(mntpnt);
	}

	return 0;
}
