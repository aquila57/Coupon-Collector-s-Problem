/* getstrl.c - Calculate Stirling Number, 2nd Kind  Version 0.1.0    */
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

/* obtain the stirling number of the second kind */
double getstrl(double m, double n)
   {
   double i;
   double nfact;
   double sum;
   double stirl;
   if (n > m)
      {
      fprintf(stderr,"getstrl: n %f > m %f\n", n, m);
      exit(1);
      } /* n is larger than m */
   nfact = factorial(n);
   sum = 0.0;
   i = 0.0;
   while (i <= n)
      {
      double sign;
      double combo;
      double pwr;
      sign = pow(-1.0, i);
      combo = ncr(n,i);
      pwr = pow(n-i, m);
      sum += (sign * combo * pwr);
      i += 1.0;
      } /* for i = 0 to n */
   stirl = sum / nfact; 
   return(stirl);
   } /* getstrl */
