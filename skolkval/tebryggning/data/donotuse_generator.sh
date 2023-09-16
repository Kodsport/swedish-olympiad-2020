#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_random.py

samplegroup
sample 1
sample 2

group g1 20
limits maxk=1
tc_manual g1

tc randk-01 gen_random maxk=1
tc randk-02 gen_random maxk=1
tc randk-03 gen_random maxk=1
tc randk-04 gen_random maxk=1
tc randk-05 gen_random maxk=1
tc randk-06 gen_random maxk=1
tc randk-07 gen_random maxk=1

group g2 80
include_group g1
tc 1
tc 2
tc_manual g2
tc_manual g3
tc_manual g4
tc_manual g5

tc rand-01 gen_random
tc rand-02 gen_random
tc rand-03 gen_random
tc rand-04 gen_random
tc rand-05 gen_random
tc rand-06 gen_random
tc rand-07 gen_random
