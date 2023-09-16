#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution fe100.cpp

samplegroup
sample 1

group g1 20
limits n=3 m=3
tc_manual g1
tc_manual ../manual_tests/3x3-0
tc_manual ../manual_tests/3x3-9
tc_manual ../manual_tests/spiral-small
tc_manual ../manual_tests/3x1
tc_manual ../manual_tests/1x3

group g2 20
limits lim=0
tc_manual g2
tc_manual ../manual_tests/unique
tc_manual ../manual_tests/1x7
tc_manual ../manual_tests/7x1

group g3 20
limits lim=2
include_group g2
tc_manual g3
tc_manual ../manual_tests/spiral
tc 1

group g4 40
include_group g1
include_group g2
include_group g3
tc_manual g4
tc_manual g5
tc_manual ../manual_tests/7x7-0
tc_manual ../manual_tests/7x7-9
