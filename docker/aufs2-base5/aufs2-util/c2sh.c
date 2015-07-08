
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
#include <linux/aufs_type.h>

#define AUFS_WH_PFX2	AUFS_WH_PFX AUFS_WH_PFX

int
main(int argc, char *argv[])
{
#define p(m, v, fmt)	printf("%s=" fmt "\n", m, v)
#define pstr(m)		p(#m, m, "%s")
#define pint(m)		p(#m, m, "%d")
	pstr(AUFS_VERSION);
	pint(AUFS_SUPER_MAGIC);
	printf("AUFS_SUPER_MAGIC_HEX=0x%x\n", AUFS_SUPER_MAGIC);
	pstr(AUFS_WH_PFX);
	pstr(AUFS_WH_PFX2);
	pstr(AUFS_WKQ_NAME);
	pstr(AUFS_WH_DIROPQ);
	pstr(AUFS_WH_BASE);
	pstr(AUFS_WH_PLINKDIR);
	pstr(AUFS_WH_ORPHDIR);
	//pint(AUFS_BRANCH_MAX);
	return 0;
}
