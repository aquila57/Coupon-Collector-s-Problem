/* calcchi.c - Chi Square Test  Version 0.1.0                        */
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

/* calculate chi square for actual distribution */
void calcchi(double *tally, int n, int maxlen, int size)
   {
   int i;
   int max_k;
   double dbln;
   /* When maxtally is less than SIZE, there are */
   /* tallies less than 10 in the tail to the right */
   double maxtally;
   double dblsz;       /* floating point SIZE */
   double lgth;        /* the number of generations in each block */
   double prob;        /* expected probability */
   double expected;    /* expected tally */
   double diff;        /* tally - expected */
   double diffsq;      /* diff * diff */
   double chisq;       /* chi square */
   double totact;      /* total tally in chi square <= SIZE */
   double df;          /* degrees of freedom */
   double minchi;      /* minimum chi square at 95% */
   double maxchi;      /* maximum chi square at 95% */
   double pvalue;      /* chi square p-value */
   printf("Length        Actual          "
      "Expected         Difference\n");
   dblsz = (double) size;
   dbln = (double) n;
   totact = maxtally = 0.0;
   max_k = 0;
   chisq = 0.0;
   lgth = (double) n;    /* lgth = n to maxlen */
   i = n;
   while (i <= maxlen)
      {
      if (tally[i] < 10.0) break;
      if (tally[i] > maxtally)
	 {
         maxtally = tally[i];
	 max_k = i;
	 } /* if new max tally */
      prob = getprob(dbln, lgth);
      expected = prob * dblsz;
      totact += tally[i];
      diff = tally[i] - expected;
      diffsq = diff * diff;
      chisq += (diffsq / expected);
      printf("%4d %15.0f %20.5f %16.5f\n",
         i, tally[i], expected, diff);
      i++;
      lgth += 1.0;
      } /* for each block length */
   df = (double) (i - n - 1);    /* degrees of freedom */
   minchi = gsl_cdf_chisq_Pinv(0.025,df);
   maxchi = gsl_cdf_chisq_Pinv(0.975,df);
   pvalue = gsl_cdf_chisq_P(chisq,df);
   printf("\n");
   printf("total actual %.0f\n", totact);
   printf("max k %d max tally %.0f\n", max_k, maxtally);
   printf("maximum length of blocks %d\n", maxlen);
   printf("Chi square %f  P-value %18.15f\n", chisq, pvalue);
   printf("\n");
   printf("At 95%c probability and %.0f degrees of freedom,\n"
      "Chi square ranges from %f to %f\n",
      '%', df, minchi, maxchi);
   } /* calcchi */
