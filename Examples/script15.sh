#!/bin/sh
# invoke with at least one argument.
# Try invoking the script with numeric and non-numeric 
# arguments, as well as integer and non-integer arguments

expr "$1" + 0 > /dev/null 2>&1
# note the redirection of stdout and stderr
echo expr returned $?
