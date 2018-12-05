#!/bin/sh
# this script runs with -x option set
# invoke with at least one numeric argument

set -x
OUT=`expr $1 + 1`
echo 1 + $1 is $OUT
exit
