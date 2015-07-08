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

/*
 * The main purpose of this script is updating /etc/mtab and calling auplilnk.
 * This behaviour is highly depending on mount(8) in util-linux package.
 */

#define _XOPEN_SOURCE	500	/* getsubopt */
#define _BSD_SOURCE		/* dirfd */

#include <sys/types.h>
#include <dirent.h>
#include <mntent.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#include <linux/aufs_type.h>
#include "au_util.h"

enum { Remount, Bind, Update, Verbose, AuFlush, LastOpt };
static void test_opts(char opts[], unsigned char flags[])
{
	int c;
	char *p, *o, *val, *pat[] = {
		[Remount]	= "remount",
		[Bind]		= "bind",
		NULL
	};

	o = strdup(opts);
	if (!o)
		AuFin("stdup");

	p = o;
	while (*p) {
		c = getsubopt(&p, pat, &val);
		switch (c) {
		case Remount:
			flags[Remount] = 1;
			break;
		case Bind:
			flags[Bind] = 1;
			break;
		}
	}
	free(o);
}

static int test_flush(char opts[])
{
	int err, i;
	regex_t preg;
	char *p, *o;
	const char *pat = "^((add|ins|append|prepend|del)[:=]"
		"|(mod|imod)[:=][^,]*=ro"
		"|(noplink|ro)$)";


	o = strdup(opts);
	if (!o)
		AuFin("stdup");

	p = o;
	i = 1;
	while ((p = strchr(p, ','))) {
		i++;
		*p++ = 0;
	}

	/* todo: try getsubopt(3)? */
	err = regcomp(&preg, pat, REG_EXTENDED | REG_NOSUB);
	if (err)
		AuFin("regcomp");

	p = o;
	while (i--) {
		if (!regexec(&preg, p, 0, NULL, 0)) {
			err = 1;
			break;
		} else
			p += strlen(p) + 1;
	}
	regfree(&preg);
	free(o);

	return err;
}

static void do_mount(char *dev, char *mntpnt, int argc, char *argv[],
		     unsigned char flags[])
{
	int i;
	const int ac = argc + 6;
	char *av[ac], **a;

	/* todo: eliminate the duplicated options */
	a = av;
	*a++ = "mount";
	*a++ = "-i";
	if (!flags[Bind] || !flags[Update])
		*a++ = "-n";
	if (flags[Bind] && flags[Verbose])
		*a++ = "-v";
	*a++ = "-t";
	*a++ = AUFS_NAME;

	for (i = 3; i < argc; i++)
		if (strcmp(argv[i], "-v") && strcmp(argv[i], "-n"))
			*a++ = argv[i];
	*a++ = dev;
	*a++ = mntpnt;
	*a++ = NULL;

#ifdef DEBUG
	for (i = 0; av[i] && i < ac; i++)
		puts(av[i]);
	exit(0);
#endif
	execvp("mount", av);
	AuFin("mount");
}

/* ---------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
	int err, c, status;
	pid_t pid;
	unsigned char flags[LastOpt];
	struct mntent ent;
	char *dev, *mntpnt, *opts, *cwd;
	DIR *cur;

	if (argc < 3) {
		errno = EINVAL;
		AuFin(NULL);
	}

	memset(flags, 0, sizeof(flags));
	flags[Update] = 1;
	opts = NULL;

	/* mount(8) always passes the arguments in this order */
	dev = argv[1];
	mntpnt = argv[2];
	while ((c = getopt(argc - 2, argv + 2, "nvo:")) != -1) {
		switch (c) {
		case 'n':
			flags[Update] = 0;
			break;
		case 'v':
			flags[Verbose] = 1;
			break;
		case 'o':
			opts = optarg;
			break;
		case '?':
		case ':':
			errno = EINVAL;
			AuFin("internal error");
		}
	}

	cur = opendir(".");
	if (!cur)
		AuFin(".");
	err = chdir(mntpnt);
	if (err)
		AuFin(mntpnt);
	cwd = getcwd(NULL, 0); /* glibc */
	if (!cwd)
		AuFin("getcwd");
	err = fchdir(dirfd(cur));
	if (err)
		AuFin("fchdir");
	closedir(cur); /* ignore */

	if (opts)
		test_opts(opts, flags);

	if (!flags[Bind] && flags[Update]) {
		err = access(MTab, R_OK | W_OK);
		if (err)
			AuFin(MTab);
	}

	if (flags[Remount]) {
		errno = EINVAL;
		if (flags[Bind])
			AuFin("both of remount and bind are specified");
		flags[AuFlush] = test_flush(opts);
		if (flags[AuFlush]) {
			err = au_plink(cwd, AuPlink_FLUSH, 1, 1);
			if (err)
				AuFin(NULL);
		}
	}

	pid = fork();
	if (!pid) {
		/* actual mount operation */
		do_mount(dev, mntpnt, argc, argv, flags);
		return 0;
	} else if (pid < 0)
		AuFin("fork");

	err = waitpid(pid, &status, 0);
	if (err < 0)
		AuFin("child process");

	err = !WIFEXITED(status);
	if (!err)
		err = WEXITSTATUS(status);

	if (!err && !flags[Bind]) {
		if (flags[Update])
			err = au_update_mtab(cwd, flags[Remount],
					     flags[Verbose]);
		else if (flags[Verbose]) {
			/* withoug blocking plink */
			err = au_proc_getmntent(cwd, &ent);
			if (!err)
				au_print_ent(&ent);
			else
				AuFin("internal error");
		}
	}

	return err;
}
