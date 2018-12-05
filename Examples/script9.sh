#!/bin/sh
# invoke this script with MYVAR
#   - not defined
#   - defined just to be a shell variable
#   - defined to be an ENVIRONMENT variable

echo this is script $0 with pid $$
echo value of variable MYVAR is \"$MYVAR\"
