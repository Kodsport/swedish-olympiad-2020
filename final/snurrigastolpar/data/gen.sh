#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution hugoe.cpp

compile gen_random.py
compile gen_line.py
compile gen_plus.py
compile gen_verydense.py
compile gen_diagonals.py
compile gen_lines.py
compile gen_almostperfect.py
compile gen_almostline.py
compile gen_almostplus.py
compile gen_denserect.py

samplegroup
limits nMax=1000 mMax=1000000000
sample 1
sample 2
sample 3
sample 4

group group1 19
limits nMax=25 mMax=5
tc 1
tc 2
tc 4
tc brute_force_1 gen_random n=1 m=5
tc brute_force_2 gen_random n=5 m=5
tc brute_force_3 gen_random n=13 m=5
tc brute_force_4 gen_line n=4 m=5
tc brute_force_5 gen_plus n=7 m=5
tc brute_force_6 gen_verydense n=7 m=5
tc brute_force_7 gen_verydense n=21 m=5
tc brute_force_8 gen_verydense n=23 m=5
tc brute_force_9 gen_diagonals n=8 m=5
tc_manual ../manual_tests/a1.in
tc_manual ../manual_tests/a2.in
tc_manual ../manual_tests/a3.in
tc_manual ../manual_tests/a4.in
tc_manual ../manual_tests/a5.in
tc_manual ../manual_tests/a6.in
tc_manual ../manual_tests/a7.in

group group2 16
limits nMax=80 mMax=80
include_group group1
tc small_mn_1 gen_random n=80 m=80
tc small_mn_2 gen_random n=79 m=80
tc small_mn_3 gen_line n=50 m=80
tc small_mn_4 gen_plus n=50 m=80
tc small_mn_5 gen_plus n=70 m=80
tc small_mn_6 gen_plus n=80 m=80
tc small_mn_7 gen_verydense n=48 m=80
tc small_mn_8 gen_verydense n=80 m=80
tc small_mn_9 gen_diagonals n=30 m=80
tc small_mn_10 gen_diagonals n=80 m=80
tc small_mn_11 gen_lines n=49 m=80
tc small_mn_12 gen_lines n=73 m=80
tc small_mn_13 gen_lines n=80 m=80
tc small_mn_14 gen_almostperfect n=80 m=80
tc small_mn_15 gen_almostperfect n=78 m=80
tc small_mn_16 gen_almostperfect n=73 m=80
tc small_mn_17 gen_almostline n=75 m=80
tc small_mn_18 gen_almostline n=80 m=80

group group3 20
limits nMax=80 mMax=1000000000
include_group group1
include_group group2
tc 3
tc small_n_1 gen_line n=76 m=1000000000
tc small_n_2 gen_almostline n=80 m=1000000000
tc small_n_3 gen_almostline n=75 m=1000000000
tc small_n_4 gen_plus n=50 m=1000000000
tc small_n_5 gen_plus n=70 m=1000000000
tc small_n_6 gen_plus n=80 m=1000000000
tc small_n_7 gen_almostplus n=74 m=1000000000
tc small_n_8 gen_almostplus n=77 m=1000000000
tc small_n_9 gen_diagonals n=30 m=1000000000
tc small_n_10 gen_diagonals n=80 m=1000000000
tc small_n_11 gen_lines n=49 m=1000000000
tc small_n_12 gen_lines n=73 m=1000000000
tc small_n_13 gen_lines n=80 m=1000000000
tc small_n_14 gen_almostperfect n=80 m=1000000000
tc small_n_15 gen_almostperfect n=78 m=1000000000
tc small_n_16 gen_almostperfect n=73 m=1000000000
tc small_n_17 gen_almostperfect n=69 m=1000000000
tc small_n_18 gen_almostperfect n=79 m=1000000000
tc small_n_19 gen_random n=80 m=20
tc small_n_20 gen_random n=80 m=40

group group4 45
limits nMax=1000 mMax=1000000000
include_group group3
tc full_1 gen_random n=300 m=100
tc full_2 gen_random n=657 m=100
tc full_3 gen_random n=999 m=200
tc full_4 gen_almostline n=1000 m=2000
tc full_5 gen_almostplus n=1000 m=2000
tc full_6 gen_almostplus n=999 m=1000000000
tc full_7 gen_diagonals n=1000 m=10000
tc full_8 gen_almostperfect n=998 m=1000000000
tc full_9 gen_almostperfect n=999 m=1000000000
tc full_10 gen_almostperfect n=1000 m=1000000000
tc full_11 gen_almostperfect n=1000 m=1000000000
tc full_12 gen_verydense n=400 m=1000000000
tc full_13 gen_verydense n=700 m=1000000000
tc full_14 gen_verydense n=1000 m=1000000000
tc full_15 gen_verydense n=1000 m=1000000000
tc full_16 gen_denserect n=1000 m=1000000000
tc full_17 gen_denserect n=1000 m=1000000000
tc full_18 gen_denserect n=1000 m=1000000000 bigx=1
tc full_19 gen_denserect n=1000 m=1000000000 bigx=1
