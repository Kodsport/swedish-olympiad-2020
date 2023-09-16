#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_exact.py
compile gen_echo.py

samplegroup
sample 1
sample 2
sample 3

group g1 40
limits subtask=1
tc 1
for x in {0..2}; do
  tc exact-$x gen_exact n=$x
done
for x in {4..16}; do
  tc exact-$x gen_exact n=$x
done

group g2 60
include_group g1
tc 2
tc 3
tc_manual g1
tc_manual g2
tc_manual g3
tc_manual g4
tc min gen_echo n=1
tc max gen_echo n=10000
