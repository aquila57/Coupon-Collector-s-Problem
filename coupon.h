/* coupon.h - Coupon Collector's Test header file  Version 0.1.0 */
/* Copyright (C) 2020 aquila57 at github.com */

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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/times.h>
#include <math.h>
#include <errno.h>
#include <gsl/gsl_sf_erf.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_rng.h>
#include "eegl.h"
#include "etaus.h"

/* SIZE is the total number of tuples    */
/* Each tuple has enough generations     */
/* to produce the n-th coupon.           */ 
/* A tuple is incomplete if it does not  */
/* contain all coupons.                  */
/* Sampling is done with replacement.    */

#define SIZE 1000000

#define EOFDIE (-999999999.0)

typedef struct xxstruct {
   char *rngname;
   char dieharder_rngname[128];
   char rngtbl[1000][64];
   int generator;
   int eofsw;
   unsigned int maxint;
   int smpls;
   double dblsmpls;
   double count;
   double modulus;
   double maxint_tbl[2048];
   } xxfmt;

/* obtain the stirling number of the second kind */
double getstrl(double m, double n);

/* combinations(n,r)                   */
double ncr(double n, double r);

/* permutations(n,k)                 */
double npk(double n, double k);

/* calculate chi square for actual distribution */
void calcchi(double *tally, int n, int maxlen, int size);

/* calculate bitcoupon chi square for actual distribution */
void calcchib(double *tally, int n, int maxlen);

/* calculate factorial(n)  */
double factorial(double n);

/* obtain the probability of expected tally */
double getprob(double d, double r);

void bld_maxint(xxfmt *xx);
void bld_rngtbl(xxfmt *xx);
void diepfx(xxfmt *xx);
double getdie(xxfmt *xx);
