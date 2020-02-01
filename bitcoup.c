/* bitcoup.c - Bit Coupon Collector's Test  Version 0.1.0            */
/* Copyright (C) 2020  aquila57 at github.com                        */

/* This program is free software; you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License as    */
/* published by the Free Software Foundation; either version 2 of    */
/* the License, or (at your option) any later version.               */

/* This program is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of    */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      */
/* GNU General Public License for more details.                      */

/* You should have received a copy of the GNU General Public License */
/* along with this program; if not, write to:                        */

   /* Free Software Foundation, Inc.                                 */
   /* 59 Temple Place - Suite 330                                    */
   /* Boston, MA 02111-1307, USA.                                    */

#include "coupon.h"

int main(void)
   {
   int i;
   int n;
   int maxlen;
   int numdgts;
   char dgts[64];
   double tally[16384];
   eefmt *ee;
   n = 2;
   ee = (eefmt *) eeglinit();
   for (i=0;i<16384;i++) tally[i] = 0.0;
   numdgts = 64;
   maxlen = 0;
   i = SIZE;
   while (i--)
      {
      int j;
      int kount;
      int totdgts;
      for (j=0;j<numdgts;j++) dgts[j] = 0;
      totdgts = kount = 0;
      while (1)
         {
         int k;
	 kount++;
         k = eeglint(ee,n);
	 if (dgts[k] == 1) continue;
	 dgts[k] = 1;
	 totdgts++;
	 if (totdgts >= n) break;
	 } /* search loop */
      if (kount > maxlen) maxlen = kount;
      tally[kount] += 1.0;
      } /* for each complete block */
   printf("\t  Bit Coupon Collector's Test\n");
   printf("\t\teegl64 Generator\n");
   printf("\n");
   calcchi(tally, n, maxlen, SIZE);
   free(ee->state);
   free(ee);
   return(0);
   } /* main */
