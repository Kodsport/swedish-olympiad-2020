#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution nils_100.cpp

compile gen_sameci.py
compile gen_random.py

samplegroup
sample 1
sample 2

group g1 20
limits maxn=2
tc_manual g2
tc n2-01 gen_random n=2
tc n2-02 gen_random n=2
tc n2-03 gen_random n=2
tc n2-04 gen_random n=2
tc n2-05 gen_random n=2
tc n2-06 gen_random n=2
tc n2-07 gen_random n=2
tc n2-08 gen_random n=2
tc n2-09 gen_random n=2
tc n2-10 gen_random n=2
tc n2-11 gen_random n=2
tc n2-12 gen_random n=2
tc n2-13 gen_random n=2
tc n2-14 gen_random n=2
tc n2-15 gen_random n=2
tc n2-16 gen_random n=2
tc n2-17 gen_random n=2
tc n2-18 gen_random n=2
tc n2-19 gen_random n=2
tc_manual n2-2
tc_manual n2-3
tc_manual n2-4
tc_manual n2-5

group g2 20
limits samesc=1
tc_manual g1
tc same-01 gen_sameci
tc same-02 gen_sameci
tc same-03 gen_sameci
tc same-04 gen_sameci
tc same-05 gen_sameci
tc same-06 gen_sameci
tc same-07 gen_sameci
tc same-08 gen_sameci

group g3 60
include_group g1
include_group g2
tc 1
tc 2
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
tc rand-08 gen_random
tc rand-09 gen_random
tc rand-10 gen_random
