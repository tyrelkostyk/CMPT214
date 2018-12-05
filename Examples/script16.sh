#!/bin/sh
# invoke with at least one numeric argument

echo "determining if your number less than 0 (1-yes, 0-no):"
expr $1 \< 0
