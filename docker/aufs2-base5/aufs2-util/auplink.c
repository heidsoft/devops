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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "au_util.h"

static void usage(char *me)
{
	fprintf(stderr,
		"usage: %s aufs_mount_point list|cpup|flush\n"
		"'list' shows the pseudo-linked inode numbers and filenames.\n"
		"'cpup' copies-up all pseudo-link to the writeble branch.\n"
		"'flush' calls 'cpup', and then 'mount -o remount,clean_plink=inum'\n"
		"and remove the whiteouted plink.\n", me);
	exit(EINVAL);
}

int main(int argc, char *argv[])
{
	int err, cmd;
	char *cwd;

	if (argc != 3)
		usage(argv[0]);

	if (!strcmp(argv[2], "flush"))
		cmd = AuPlink_FLUSH;
	else if (!strcmp(argv[2], "list"))
		cmd = AuPlink_LIST;
	else if (!strcmp(argv[2], "cpup"))
		cmd = AuPlink_CPUP;
	else {
		errno = EINVAL;
		AuFin(argv[2]);
		cmd = 0; /* never reach here */
	}

	err = chdir(argv[1]);
	if (err)
		AuFin("chdir");
	cwd = getcwd(NULL, 0); /* glibc */
	if (!cwd)
		AuFin("getcwd");
	return au_plink(cwd, cmd, 1, 0);
}
