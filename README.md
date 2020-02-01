# Coupon Collector's Problem

See REFERENCES for information about the Coupon Collector's
Problem, including the Wikipedia article.

The tests in this repository are applied against a variety
of random number generators, some weak and some strong.
The purpose of this repository is to show how the Coupon
Collector's Problem is solved, and what types of generators
pass or fail the test.

The results from this test are placed in a chi square test
to give a p-value for pass or fail.  A p-value less than
0.01 or greater than 0.99 is considered a fail.

Random number generators used in this test.

eegl64

The eegl64 random number generator is explained in the repository
"eegl64".  That is a random number generator based on a 64 bit
LFSR with a Bays Durham shuffle.  The period length of the eegl64
generator approximates 1.2 * 10^61036 generations.  That is a long
period length, that never terminates, or wraps around.  The eegl64
generator passes this test.

----------------

etaus

The eetaus random number generator is explained in the repository
"etaus".  That is a random number generator based on the Tausworthe
algorithm by Pierre L'Ecuyer at the University of Montreal.
Etaus uses the Bays-Durham shuffle.  The period length of this
generator approximates 1.2 * 10^61036 generations.  That is a
long period length, that never terminates, or wraps around.  The
etaus generator passes this test.

----------------

Fibonacci

The fibonacci random number generator illustrates how a weak
random number generator fails this test.

fibonum1 = fibonum2
fibonum2 = fibonum3
fibonum3 = fibonum1 + fibonum2
fraction = fibonum3 / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

LFSR

The LFSR random number generator illustrates how a weak
random number generator fails this test.

See the macro MYLFSR at the beginning of the program for the
algorithm used in the LFSR generator.  The LFSR generator used
is a 64 bit linear feedback shift register with a period length
of 2^64.

MYLFSR;
fraction = lfsr / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

RANDU

The RANDU random number generator illustrates how a weak
random number generator is able to pass this test some of
the time.

RANDU is a 32 bit generator with a period length of 2^30.

seed *= 65539;
fraction = seed / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

Sine Wave Generator

The sine random number generator illustrates how a weak
random number generator fails this test.

The sine generator has a long enough period length to complete
the test.

/* generate a uniform number between zero and PI */
theta = eeglunif(ee) * M_PI;
sinx = sin(theta);

sinx is a pseudo random number with a sine distribution
ranging from zero to one.

----------------

GNU Scientific Library Generators

The GSL generators illustrate how a variety of strong random
number generators perform well in this test.

fraction = gsl_rng_uniform(rng);

fraction is a strong random number with a uniform distribution
ranging from zero to one.

The following GSL generators fail the Coupon Collector's Problem.
The generators, which fail this test, also perform poorly in other
random number tests.

random-32-bsd

random-32-glibc2

random-32-libc5

random-64-bsd

random-64-glibc2

random-64-libc5

ranlxs1

slatec

uni

uni32

----------------

Dieharder generators

The dieharder package contains 74 well known random number
generators.  Dieharder can generate 32 bit unsigned integers
from these generators with the following command.

dieharder -g nnn -t yyy -o

where nnn is the three digit number of the generator, and
yyy is the number of integers to generate.

For example,

dieharder -g 053 -t 1000 -o

This example generates one thousand 32 bit integers using
the taus2 generator.  053 is the number of the taus2 generator.

To see all the generator numbers, run the following command.

dieharder -g -l

The Coupon Collector's command for dieharder generators in this
repository is called tstdie.sh.  The parameter for this command
is the dieharder generator number.  For example,

tstdie.sh 053

This runs the test using the taus2 generator from dieharder.

The following dieharder generators fail this test.

random-32-bsd

random-32-glibc2

random-32-libc5

ranlxs1

-----------------------------------------------------------

The following are the subroutines used in the Coupon Collector's
Problem.

getprob.c - calculate the probability of a tuple length
for the chi square test.

getstrl.c - calculate Stirling number of the second kind.
This subroutine is called by getprob.c.

ncr.c - calculate the combinations of n, taken r at a time.
This subroutine is called by getstrl.c.

npk.c - calculate permutations, called by ncr.c.

factorial.c - calculate the factorial n!

calcchi.c - calculate the chi square test based on the length
of each tuple.  A tuple is the number of coupons it takes to
achieve a complete list of coupons.

calcchib.c - calculate the chi square test based on the length
of each tuple.  A tuple is the number of coupons it takes to
achieve a complete list of coupons.  This version of the chi
square test is used in bitcoup.c.

bld_maxint.c - for dieharder generators, build a table of maximum
integers unique to each generator.

bld_rngtbl.c - for dieharder, maintain a table of generator names
associated with each generator number.

diepfx.c - bypass the header in the output file from dieharder.

getdie.c - read one uniform random number generated by dieharder.

Eegl64 subroutines.

eeglabt.c - print copyright and a summary of the GNU Public License.

eeglbit.c - output a random bit

eegl.c - core randomizer, outputs a 32 bit unsigned integer.

eeglcrc.c - calculate the crc for the initial seed.

eegldspl.c - display the internal state of the generator.

eeglfrac.c - generate a 53 bit fraction between zero and one.

eeglinit.c - initialize the generator based on date, time, and
number of ticks since the machine was booted.

eeglint.c - generate a random integer between zero and a limit
minus one.

eeglpwr.c - generate from 1 to 32 random bits.

eeglsd.c - generate a random seed based on a crc calculation.

eeglstrt.c - initialize the generator based on three seed parameters.

eeglunif.c - generate a 32 bit fraction between zero and one.

Etaus generator.  Each subroutine corresponds to the eegl64
subroutine, above, with the same name and features.

etausabt.c

etausbit.c

etaus.c

etausdspl.c

etausfrac.c

etausinit.c

etausint.c

etauspwr.c

etausstrt.c

etausunif.c

--------------------------------------------------------------

If you have a random number generator that you want to include
in this repository, you are welcome to submit your generator for
inclusion.

Read the INSTALL and TESTING documents for more information
about how to use this repository.  Read REFERENCES for information
about the Coupon Collector's Problem.

