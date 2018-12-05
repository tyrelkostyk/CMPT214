#!/bin/sh
# invoke with at least one numeric argument

/bin/echo -n "one more than $1 is "
expr $1 + 1
