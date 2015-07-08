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

#ifndef __AUFS_UTIL_H__
#define __AUFS_UTIL_H__

#include <errno.h>
#include <error.h>

#define AuFin(fmt, args...) \
	error_at_line(errno, errno, __FILE__, __LINE__, fmt, ##args)

#ifdef DEBUG
#define MTab "/tmp/mtab"
#else
#define MTab "/etc/mtab"
#endif

/* proc_mounts.c */
struct mntent;
int au_proc_getmntent(char *mntpnt, struct mntent *rent);

/* br.c */
int au_br(char ***br, int *nbr, struct mntent *ent);

/* plink.c */
enum {
	AuPlink_FLUSH,
	AuPlink_CPUP,
	AuPlink_LIST
};
int au_plink(char cwd[], int cmd, int begin_maint, int end_maint);
void au_plink_maint(char *path);

/* mtab.c */
void au_print_ent(struct mntent *ent);
int au_update_mtab(char *mntpnt, int do_remount, int do_verbose);

#define _Dpri(fmt, args...)	printf("%s:%d:" fmt, __func__, __LINE__, ##args)
#ifdef DEBUG
#define Dpri(fmt, args...)	_Dpri(fmt, ##args)
#else
#define Dpri(fmt, args...)	do { } while(0)
#endif

#endif /* __AUFS_UTIL_H__ */
