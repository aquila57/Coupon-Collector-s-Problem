#!/bin/bash
if [ -z $1 ]
then
echo "Usage: $0 n"
echo "Example: $0 5"
exit 1
fi
cat alldie.lst | alldie.sh $1 $2 >alldie.out
