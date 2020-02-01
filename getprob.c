/* getprob.c - Calculate probability  Version 0.1.0                  */
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

/* obtain the probability of expected tally */
double getprob(double d, double r)
   {
   double dfact;        /* factorial d! */
   double pwr;          /* d^r          */
   double strl;         /* stirling number of the second kind */
   double prob;         /* expected probability */
   /* this error should never happen */
   if (r < d)
      {
      fprintf(stderr,"getprob: r %.0f < "
         "d %.0f\n", r, d);
      exit(1);
      } /* r < d */
   dfact = factorial(d);
   pwr = pow(d,r);
   strl = getstrl(r-1.0, d-1.0);    /* find stirling # */
   prob = dfact * strl / pwr;       /* probability calculation */
   return(prob);
   } /* getprob */
