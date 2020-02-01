#!/bin/bash
if [ -z $1 ]
then
echo "Coupon Collector's Test with GNU Scientific Library"
echo "random number generators"
echo "Usage: $0 n"
echo "Where n is number of coupons (2-12)"
echo "Example: $0 5"
exit 1
fi
cat allgsl.lst | allgsl.sh $1 >allgsl.out
