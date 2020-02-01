#  couponlib.mak - Compile coupon subroutine library Version 0.1.0
#  Copyright (C) 2020 aquila57 at github.com

#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License as
#  published by the Free Software Foundation; either version 2 of
#  the License, or (at your option) any later version.

#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to:

   #  Free Software Foundation, Inc.
   #  59 Temple Place - Suite 330
   #  Boston, MA 02111-1307, USA.

#--------------------------------------------------------
#  The LFSR in this generator comes from the following
#  website http://www.xilinx.com/support/documentation/
#  application_notes/xapp052.pdf
#--------------------------------------------------------

OBJ=getstrl.o \
	ncr.o \
	npk.o \
	factorial.o \
	calcchi.o \
	calcchib.o \
	bld_maxint.o \
	bld_rngtbl.o \
	diepfx.o \
	getdie.o \
	getprob.o \
	eeglcrc.o \
	eeglsd.o \
	eeglinit.o \
	eeglstrt.o \
	eegl.o \
	eeglint.o \
	eeglpwr.o \
	eeglbit.o \
	eeglunif.o \
	eeglfrac.o \
	eegldspl.o \
	eeglabt.o \
	etausinit.o \
	etausstrt.o \
	etaus.o \
	etausint.o \
	etauspwr.o \
	etausbit.o \
	etausunif.o \
	etausfrac.o \
	etausdspl.o \
	etausabt.o

CC=gcc

AR=ar

CFLAGS=-c -Wall -O2

LDFLAGS=

libcoupon.a:			$(OBJ)
		rm -f libcoupon.a
		$(AR) r libcoupon.a $(OBJ)

getstrl.o:			getstrl.c
		$(CC) $(CFLAGS) getstrl.c

ncr.o:				ncr.c
		$(CC) $(CFLAGS) ncr.c

npk.o:				npk.c
		$(CC) $(CFLAGS) npk.c

factorial.o:			factorial.c
		$(CC) $(CFLAGS) factorial.c

calcchi.o:			calcchi.c
		$(CC) $(CFLAGS) calcchi.c

calcchib.o:			calcchib.c
		$(CC) $(CFLAGS) calcchib.c

bld_maxint.o:			bld_maxint.c
		$(CC) $(CFLAGS) bld_maxint.c

bld_rngtbl.o:			bld_rngtbl.c
		$(CC) $(CFLAGS) bld_rngtbl.c

diepfx.o:			diepfx.c
		$(CC) $(CFLAGS) diepfx.c

getdie.o:			getdie.c
		$(CC) $(CFLAGS) getdie.c

getprob.o:			getprob.c
		$(CC) $(CFLAGS) getprob.c

eeglcrc.o:			eeglcrc.c
		$(CC) $(CFLAGS) eeglcrc.c

eeglsd.o:			eeglsd.c
		$(CC) $(CFLAGS) eeglsd.c

eeglinit.o:			eeglinit.c
		$(CC) $(CFLAGS) eeglinit.c

eeglstrt.o:			eeglstrt.c
		$(CC) $(CFLAGS) eeglstrt.c

eegl.o:				eegl.c
		$(CC) $(CFLAGS) eegl.c

eeglint.o:			eeglint.c
		$(CC) $(CFLAGS) eeglint.c

eeglpwr.o:			eeglpwr.c
		$(CC) $(CFLAGS) eeglpwr.c

eeglbit.o:			eeglbit.c
		$(CC) $(CFLAGS) eeglbit.c

eeglunif.o:			eeglunif.c
		$(CC) $(CFLAGS) eeglunif.c

eeglfrac.o:			eeglfrac.c
		$(CC) $(CFLAGS) eeglfrac.c

eegldspl.o:			eegldspl.c
		$(CC) $(CFLAGS) eegldspl.c

eeglabt.o:			eeglabt.c
		$(CC) $(CFLAGS) eeglabt.c

etausinit.o:			etausinit.c
		$(CC) $(CFLAGS) etausinit.c

etausstrt.o:			etausstrt.c
		$(CC) $(CFLAGS) etausstrt.c

etaus.o:			etaus.c
		$(CC) $(CFLAGS) etaus.c

etausint.o:			etausint.c
		$(CC) $(CFLAGS) etausint.c

etauspwr.o:			etauspwr.c
		$(CC) $(CFLAGS) etauspwr.c

etausbit.o:			etausbit.c
		$(CC) $(CFLAGS) etausbit.c

etausunif.o:			etausunif.c
		$(CC) $(CFLAGS) etausunif.c

etausfrac.o:			etausfrac.c
		$(CC) $(CFLAGS) etausfrac.c

etausdspl.o:			etausdspl.c
		$(CC) $(CFLAGS) etausdspl.c

etausabt.o:			etausabt.c
		$(CC) $(CFLAGS) etausabt.c

clean:
		rm -f $(OBJ) libcoupon.a
