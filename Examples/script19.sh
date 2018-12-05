#!/bin/bash
# invoke this script with a multi-character command-line argument,
#  a single-character command-line argument, and no command-line
#  argument
# execute with -x to see tracing output
# note use of /bin/echo once again
# also, the tr(1) is present to remove the \n that echo will add

/bin/echo -n "the first command-line argument had "
echo $(echo "$1" | tr -d '\n' | wc -c) 'character(s)' in it
exit
