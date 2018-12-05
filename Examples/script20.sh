#!/bin/sh
# This script expects its input to come from standard input.
# It simply counts how many characters, not including newline
# characters, there were in that input.
/bin/echo there were `tr -d '\n' | wc -c` characters on stdin
exit
