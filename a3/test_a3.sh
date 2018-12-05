#!/bin/bash
# set -x

tests=0
tests_failed=0

time_calc conv 60
let "tests++"
let "tests_failed=0"

echo $tests_failed of $tests tests failed

