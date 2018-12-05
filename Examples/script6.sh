#!/bin/sh
# invoke with "sh -v script6.sh <args>" or "sh -x script6.sh <args>"

echo program was invoked by \"$0\"
echo there were $# arguments given on the command line
echo argument 1 is \"$1\"
echo argument 2 is \"$2\"
echo turning off debugging
set -
echo argument 3 is \"$3\"
echo argument 109 is \"${109}\"
