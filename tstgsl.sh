#!/bin/bash
if [ -z $2 ]
then
echo "Coupon Collector's Test with GNU Scientific Library"
echo "random number generators"
echo "Usage: $0 n generator"
echo "Example: $0 5 taus2"
echo "Example: $0 5 mt19937"
echo "Example: $0 5 ranlxd2"
echo "Where n is the number of coupons (2-12)"
echo "For a list of GSL generators, type:"
echo "$0 5 ?"
exit 1
fi
GSL_RNG_TYPE="$2"
export GSL_RNG_TYPE
gslcoup $1
