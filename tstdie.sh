#!/bin/bash
if [ -z $2 ]
then
echo "Usage: $0 n Dieharder_RNG_number"
echo "Example: $0 5 053"
echo "To get Dieharder_RNG_number,"
echo "dieharder -g -l"
exit 1
fi
dieharder -g $2 -t 1000000 -o | diecoup $1 $2
