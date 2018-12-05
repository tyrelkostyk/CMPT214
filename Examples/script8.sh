#!/bin/sh

# start this script in the background.
# Then, with bash on LINUX, issue
#        pstree -p $$
# If on a system without pstree, try
#        ps -Tj
# or
#        ps -O ppid
echo this is script $0 with pid $$
echo now sleeping for 30 seconds
sleep 30
