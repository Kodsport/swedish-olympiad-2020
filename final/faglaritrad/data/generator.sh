#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution nils.cpp opt
#ulimit -s unlimited

compile gen_random.py
compile gen_line.py
compile gen_star.py
compile gen_staircase.py
compile gen_antigreedy.py

samplegroup
limits nMax=100000
sample 1
sample 2
sample 3

group line 12
limits nMax=100000
tc line_01 gen_line n=2 m=2 k=1
tc line_02 gen_line n=3 m=2 k=2
tc line_03 gen_line n=100000 m=100000 k=1
tc line_04 gen_line n=100000 m=100000 k=2
tc line_05 gen_line n=100000 m=77777 k=22220
tc line_06 gen_line n=100000 m=77777 k=77788
tc line_07 gen_line n=100000 m=77777 k=22225
tc line_08 gen_line n=99977 m=48999 k=45678
tc line_09 gen_line n=99977 m=311 k=45678

group small 16
limits nMax=10
tc 1
tc 2
tc 3
tc small_01 gen_random n=5 m=2
tc small_02 gen_random n=7 m=3
tc small_03 gen_random n=10 m=5
tc small_04 gen_random n=10 m=5
tc small_05 gen_random n=10 m=6
tc small_06 gen_random n=10 m=4
tc small_07 gen_random n=2 m=2
tc small_08 gen_random n=10 m=10 leaf=1
tc small_09 gen_random n=10 m=10 nonleaf=1
tc small_10 gen_line n=10 m=3 k=5
tc small_11 gen_antigreedy n=10

group medium 20
limits nMax=200
include_group small

tc medium_01 gen_random n=15 m=2
tc medium_02 gen_random n=37 m=11
tc medium_03 gen_random n=100 m=33
tc medium_04 gen_random n=199 m=57
tc medium_05 gen_random n=200 m=79
tc medium_06 gen_random n=200 m=88
tc medium_07 gen_random n=200 m=88 leaf=1
tc medium_08 gen_random n=200 m=144 leaf=1
tc medium_09 gen_random n=200 m=197 leaf=1
tc medium_10 gen_random n=200 m=200 leaf=1
tc medium_11 gen_random n=200 m=197 nonleaf=1
tc medium_12 gen_random n=200 m=200 nonleaf=1
tc medium_13 gen_star n=200 m=195 k=2
tc medium_14 gen_random n=200 m=196 width=2 leaf=1
tc medium_15 gen_line n=200 m=187 k=8
tc medium_16 gen_staircase n=200 m=193 k=1

group n_equals_m 17
limits nMax=100000

tc nm_01 gen_random n=3 m=3
tc nm_02 gen_random n=333 m=333
tc nm_03 gen_random n=33333 m=33333
tc nm_04 gen_random n=100000 m=100000
tc nm_05 gen_random n=100000 m=100000 leaf=1
tc nm_06 gen_random n=100000 m=100000 leaf=1
tc nm_07 gen_random n=100000 m=100000 width=5 leaf=1
tc nm_08 gen_random n=100000 m=100000 width=3 leaf=1
tc nm_09 gen_random n=100000 m=100000 width=2 leaf=1
tc nm_10 gen_random n=100000 m=100000 nonleaf=1
tc nm_11 gen_line n=100000 m=100000 k=100000
tc nm_12 gen_line n=100000 m=100000 k=99999
tc nm_13 gen_star n=100000 m=100000 k=75754
tc nm_14 gen_staircase n=100000 m=100000 k=2

group large 35
limits nMax=100000

include_group medium
include_group line
include_group n_equals_m

tc large_01 gen_random n=333 m=99
tc large_02 gen_random n=4444 m=1000
tc large_03 gen_random n=55555 m=10000
tc large_04 gen_random n=100000 m=40000
tc large_05 gen_random n=100000 m=20000
tc large_06 gen_random n=100000 m=20000
tc large_07 gen_random n=100000 m=20000
tc large_08 gen_random n=100000 m=2
tc large_09 gen_random n=100000 m=70000 leaf=1
tc large_10 gen_random n=100000 m=90000 leaf=1
tc large_11 gen_random n=100000 m=80000 nonleaf=1
tc large_12 gen_random n=100000 m=30000 width=5
tc large_13 gen_random n=100000 m=20000 width=3
tc large_14 gen_random n=100000 m=70000 width=3 leaf=1
tc large_15 gen_random n=100000 m=20000 width=2
tc large_16 gen_staircase n=100000 m=90001 k=5
