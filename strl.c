#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <gmp.h>

void putstx(char *pgm)
   {
   fprintf(stderr,"Calculate a stirling number "
      "of the second kind\n");
   fprintf(stderr,"Usage: %s m n\n", pgm);
   fprintf(stderr,"Example: %s 5 3\n", pgm);
   exit(1);
   } /* putstx */

double factorial(double n)
   {
   double i;
   double fact;
   fact = 1.0;
   i = n;
   while (i > 1.0)
      {
      fact *= i;
      i -= 1.0;
      } /* for each factor */
   return(fact);
   } /* factorial */

double npk(double n, double k)
   {
   double i;
   double lmt;
   double rslt;
   lmt = n - k + 1;
   rslt = 1.0;
   i = n;
   while (i >= lmt)
      {
      rslt *= i;
      i -= 1.0;
      } /* for each factor on top */
   return(rslt);
   } /* npk */

double ncr(double n, double r)
   {
   double top;
   double bot;
   top = npk(n,r);
   bot = factorial(r);
   return(top/bot);
   } /* ncr */

int main(int argc, char **argv)
   {
   int emm;
   int enn;
   double i;
   double m;
   double n;
   double nfact;
   double sum;
   double stirl;
   if (argc != 3) putstx(*argv);
   emm = atoi(*(argv+1));
   if (emm < 1 || emm > 10) putstx(*argv);
   enn = atoi(*(argv+2));
   if (enn < 1 || enn > 10) putstx(*argv);
   if (enn > emm) putstx(*argv);
   m = (double) emm;
   n = (double) enn;
   nfact = factorial(n);
   sum = 0;
   i = 0;
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
   printf("Stirling %d %d = %.0f\n",
      emm, enn, stirl);
   return(0);
   } /* main */
