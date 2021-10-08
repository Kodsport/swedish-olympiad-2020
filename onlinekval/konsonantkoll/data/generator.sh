#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution karl.py

compile gen_random.py

samplegroup
limits allowSpaces=1 maxRepeated=1000 maxLength=1000
sample 1
sample 2

group group1 50
limits allowSpaces=0 maxRepeated=3 maxLength=1000
tc 1
tc partial-01 gen_random allowSpaces=0 n=30 maxRepeated=3
tc partial-02 gen_random allowSpaces=0 n=30 maxRepeated=3
tc partial-03 gen_random allowSpaces=0 n=100 maxRepeated=3
tc partial-04 gen_random allowSpaces=0 n=100 maxRepeated=3
tc partial-05 gen_random allowSpaces=0 n=300 maxRepeated=3
tc partial-06 gen_random allowSpaces=0 n=300 maxRepeated=3
tc partial-07 gen_random allowSpaces=0 n=500 maxRepeated=3
tc partial-08 gen_random allowSpaces=0 n=500 maxRepeated=3
tc partial-09 gen_random allowSpaces=0 n=1000 maxRepeated=3
tc partial-10 gen_random allowSpaces=0 n=1000 maxRepeated=3

group group2 50
limits allowSpaces=1 maxRepeated=1000 maxLength=1000
tc 2
tc full-01 gen_random allowSpaces=1 n=30 maxRepeated=30
tc full-02 gen_random allowSpaces=1 n=10 maxRepeated=1000
tc full-03 gen_random allowSpaces=1 n=10 maxRepeated=1000
tc full-04 gen_random allowSpaces=1 n=100 maxRepeated=30
tc full-05 gen_random allowSpaces=1 n=100 maxRepeated=30
tc full-06 gen_random allowSpaces=1 n=300 maxRepeated=30
tc full-07 gen_random allowSpaces=1 n=300 maxRepeated=30
tc full-08 gen_random allowSpaces=1 n=500 maxRepeated=30
tc full-09 gen_random allowSpaces=1 n=500 maxRepeated=30
tc full-10 gen_random allowSpaces=1 n=1000 maxRepeated=30
tc full-11 gen_random allowSpaces=1 n=1000 maxRepeated=30
include_group group1
