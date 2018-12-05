#!/bin/sh
# invoke this script with MYVAR
#   - not defined (may need "unset MYVAR" command following script9.sh)
#   - defined just to be a shell variable
#   - defined to be an ENVIRONMENT variable
# check the value of MYVAR before and after the script is executed

echo this is script $0 with pid $$
echo value of MYVAR is \"$MYVAR\"
echo changing the value of MYVAR to $$
MYVAR=$$
echo value of MYVAR is now \"$MYVAR\"

