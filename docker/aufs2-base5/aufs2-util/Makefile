
# Copyright (C) 2005-2009 Junjiro Okajima
#
# This program, aufs is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301	 USA

ifndef KDIR
KDIR = /lib/modules/$(uname -r)/build
endif

CFLAGS += -I${KDIR}/include
CFLAGS += -O -Wall
LDFLAGS += -static -s

Cmd = umount.aufs auchk #aubrsync
Etc = etc_default_aufs
Bin = auplink mount.aufs #auctl
BinObj = $(addsuffix .o, ${Bin})
Lib = libau.a
LibObj = proc_mnt.o br.o plink.o mtab.o
LibHdr = au_util.h

all: ${Bin} ${Etc}

${Bin}: LDLIBS = -L. -lau
${BinObj}: %.o: %.c ${LibHdr} ${Lib}

${LibObj}: %.o: %.c ${LibHdr}
${Lib}: ${LibObj}
	${AR} r $@ $^

etc_default_aufs: c2sh aufs.shlib
	${RM} $@
	echo '# aufs variables for shell scripts' > $@
	./c2sh >> $@
	echo >> $@
	sed -e '0,/^$$/d' aufs.shlib >> $@
.INTERMEDIATE: c2sh

install_sbin: File = mount.aufs umount.aufs auplink
install_sbin: Tgt = ${DESTDIR}/sbin
install_ubin: File = auchk #aubrsync auctl
install_ubin: Tgt = ${DESTDIR}/usr/bin
install_etc: File = etc_default_aufs
install_etc: Tgt = ${DESTDIR}/etc/default/aufs
install_sbin install_ubin install_etc: ${File}
	install -m 755 -o root -g root -p ${File} ${Tgt}
install: install_sbin install_ubin install_etc

clean:
	${RM} ${Lib} ${Bin} ${Etc} ${LibObj} ${BinObj} *~

-include priv.mk
