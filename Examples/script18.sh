#!/bin/sh
# invoke this script with a command-line argument
# the script runs with -x set to show tracing output
# note use of printf(1)
# also, the tr(1) is present to remove the \n that echo will add

set -x
NUM_CHAR=`echo "$1" | tr -d '\n' | wc -c`
printf "the first command-line argument had %d characters in it\n" $NUM_CHAR
exit
