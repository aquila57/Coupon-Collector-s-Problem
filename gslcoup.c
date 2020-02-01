/* gslcoup.c - Coupon Collector's Test, GSL  Version 0.1.0           */
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

/*****************************************************************/
/* The probability distribution for the coupon collector's       */
/* problem is explained on the following web page.               */
/* University of Indiana, Computer Science Dept.                 */
/* https://www.cs.indiana.edu/~kapadia/project2/node19.html      */
/*****************************************************************/

/*****************************************************************/
/* This program generates 1 million random tuples of n           */
/* coupons.  For example, if there are three coupons, A,B,C,     */
/* n = 3.                                                        */
/* The program generates 1 million tuples to see how many        */
/* generations it takes to generate all three coupons.           */
/* The length of each tuple is then tabulated, and a chi square  */
/* test is performed on the table of tallies.                    */
/* If the tuple is "ABBAC", the length of the tuple is 5,        */
/* because it took 5 generations to "collect" all 3 coupons.     */
/* tally[5] is incremented by 1.                                 */
/*****************************************************************/

#include "coupon.h"

/* display command syntax */
void putstx(char *pgm)
   {
   fprintf(stderr,"Coupon Collector's Problem\n");
   fprintf(stderr,"Usage: %s n\n", pgm);
   fprintf(stderr,"Where n the number of "
      "coupons %c2-12%c\n", '(', ')');
   fprintf(stderr,"Example: %s 5\n", pgm);
   exit(1);
   } /* putstx */

int main(int argc, char **argv)
   {
   int i;            /* for i = 1 to SIZE */
   int n;            /* number of coupons */
   double dbln;      /* number of coupons */
   int maxlen;       /* length of longest tuple */
   int numdgts;      /* maximum number of coupons */
   char dgts[64];    /* array to check off coupons */
   double tally[16384];    /* table of tallies based on tuple length */
   gsl_rng *rng;
   gsl_rng_type *typ;
   unsigned int dttk;          /* combined date and #ticks */
   time_t now;                 /* current date and time */
   clock_t clk;                /* current number of ticks */
   struct tms t;               /* structure used by times() */
   if (argc != 2) putstx(*argv);
   n = atoi(*(argv+1));       /* get the first argument */
   if (n < 2 || n > 12) putstx(*argv);
   dbln = (double) n;
   /***************************************************/
   /* Initialize the seed to date/time/ticks          */
   /***************************************************/
   /* get clock ticks since boot                       */
   clk = times(&t);
   /* get date & time                                  */
   time(&now);
   /* combine date, time, and ticks into a single UINT */
   dttk = (unsigned int) (now ^ clk);
   /****************************************************/
   /* Initialize the random number generator           */
   /* in the GNU Scientific Library                    */
   /****************************************************/
   gsl_rng_env_setup();
   typ = (gsl_rng_type *) gsl_rng_default;
   rng = (gsl_rng *) gsl_rng_alloc(typ);
   /* allocate GSL random number generator to set initial */
   /* values in the three fibonacci numbers               */
   gsl_rng_set(rng, dttk);
   /****************************************************/
   /* initialize table of tallies to zeros */
   /****************************************************/
   for (i=0;i<16384;i++) tally[i] = 0.0;
   numdgts = 64;
   maxlen = 0;
   i = SIZE;
   while (i--)         /* for tuple = 1 to SIZE */
      {
      int j;           /* loop counter for coupons */
      int kount;       /* number of coupons in the tuple */
      int totdgts;     /* number of unique coupons */
      /***************************************************************/
      /* initialize coupon table                                     */
      /* j represents the coupon                                     */
      /* dgts[j] = 0 if the coupon has not been generated yet        */
      /* dgts[j] = 1 if the coupon has already been generated        */
      /* if all dgts[0] to dgts[n-1] = 1,                            */
      /* then the tuple is complete,                                 */
      /* and a tally is made of the length of the tuple.             */
      /***************************************************************/
      for (j=0;j<numdgts;j++) dgts[j] = 0;
      totdgts = kount = 0;
      /***************************************************************/
      /* keep generating coupons until the tuple is complete         */
      /* endless loop                                                */
      /* break if tuple is complete                                  */
      /* sampling is done with replacement                           */
      /***************************************************************/
      while (1)
         {
	 double num;
         int k;             /* coupon */
	 kount++;           /* add 1 to tuple length */
	 /* generate a coupon from 0 to n-1          */
	 num = gsl_rng_uniform(rng);
	 k = (int) floor(num * dbln);
	 /* If this coupon has already been generated, */
	 /* generate another coupon with replacement.  */
	 if (dgts[k] == 1) continue;
	 /* Flag this coupon as having been generated.  */
	 dgts[k] = 1;
	 /* add 1 to total number of unique coupons     */
	 /* 1 <= totdgts <= n                           */
	 totdgts++;
	 /* Break the loop, if the tuple is complete    */
	 if (totdgts >= n) break;
	 } /* search loop */
      /* keep track of the longest tuple in the test */
      if (kount > maxlen) maxlen = kount;
      /* add 1 to tally based on tuple length        */
      /* kount is the length of the tuple            */
      tally[kount] += 1.0;
      } /* for each complete block */
   /******************************************************************/
   /* All the sampling data has been tabulated                       */
   /* Now it is time to do the chi square test                       */
   /* Read the comments at the beginning of the program,             */
   /* about the distribution of the coupon collector's problem.      */
   /******************************************************************/
   printf("\t\tCoupon Collector's Test\n");
   printf("\t GNU Scientific Library "
      "Generator: %s\n", gsl_rng_name(rng));
   printf("\n");
   calcchi(tally, n, maxlen, SIZE);
   /******************************************************************/
   /* The coupon collector's test has ended.                         */
   /* Free up the heap                                               */
   /******************************************************************/
   gsl_rng_free(rng);
   return(0);
   } /* main */
