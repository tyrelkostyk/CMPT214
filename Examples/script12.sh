#!/bin/sh
# script to demonstrate how commands within a script can make use of
# stdin inherited from the shell executing the script

# this script counts the number of input lines that conform
# to the pattern 'cat.*cat' on either the file whose name is
# provided as a command-line argument, or from standard input
# if no command-line argument is given.  Invoke with a 
# command-line argument set to the file on which to operate, or
# else with no command-line arguments and input provided on stdin.

egrep 'cat.*cat' $1 | wc -l
