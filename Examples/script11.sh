#!/bin/bash

# after running this script, give the commands "echo $MYLOCALVAR" and
# "echo $MYENVVAR" to the shell

echo this is script $0 with pid $$

echo value of MYLOCALVAR is \"$MYLOCALVAR\"
echo setting MYLOCALVAR to "local$$"
MYLOCALVAR="local$$"
echo "value of local variable MYLOCALVAR is now $MYLOCALVAR"

echo value of MYENVVAR is \"$MYENVVAR\"
echo setting MYENVVAR to "env$$"
export MYENVVAR="env$$"
echo -n "value of environment variable MYENVVAR is now "
printenv MYENVVAR

# echo is a built-in command in sh and bash.  However, on some systems
# the sh version of (built-in) echo does not support the -n option.  There are 
# two options to deal with this problem: make the script into a bash script
# (by using #!/bin/bash instead of #!/bin/sh at the beginning of the file) 
# or use the echo command in /bin/echo.  The former solution was used above.
#
# Fortunately, sh on tuxworld supports -n.

