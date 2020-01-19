#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution hugoe.py

compile gen_random.py
compile gen_structured.py
compile gen_bign.py
compile gen_few.py

samplegroup
limits nMax=100000 dMax=364
sample 1
sample 2
sample 3

group group1 30
limits nMax=15 dMax=364
tc 1
tc 2
tc 3
tc small_n_1 gen_random n=5 d=100
tc small_n_2 gen_random n=5 d=300
tc small_n_3 gen_random n=5 d=200 impossible=1
tc small_n_4 gen_random n=14 d=250
tc small_n_5 gen_random n=14 d=270
tc small_n_6 gen_random n=15 d=270
tc small_n_7 gen_random n=15 d=303
tc small_n_8 gen_random n=15 d=300 impossible=1
tc small_n_9 gen_random n=15 d=303 impossible=1
tc small_n_10 gen_few n=15 k=3
tc small_n_11 gen_few n=15 k=4
tc small_n_12 gen_few n=15 k=5
tc small_n_13 gen_few n=15 k=6
tc small_n_14 gen_few n=15 k=7
tc_manual ../manual_tests/m1.in
tc_manual ../manual_tests/m2.in
tc_manual ../manual_tests/m4.in

group group2 40
limits nMax=100000 dMax=182
tc 1
tc 3
tc small_d_1 gen_random n=50 d=182
tc small_d_2 gen_random n=50 d=182
tc small_d_3 gen_random n=100 d=182
tc small_d_4 gen_random n=100 d=182 impossible=1
tc small_d_5 gen_random n=365 d=182
tc small_d_6 gen_random n=365 d=182 impossible=1
tc small_d_7 gen_random n=10000 d=100
tc small_d_8 gen_random n=10000 d=150
tc small_d_9 gen_random n=99998 d=182
tc small_d_10 gen_random n=99999 d=182 impossible=1
tc small_d_11 gen_random n=100000 d=5
tc small_d_12 gen_random n=100000 d=50
tc small_d_13 gen_random n=100000 d=100
tc small_d_14 gen_random n=100000 d=180
tc small_d_15 gen_random n=100000 d=100 impossible=1
tc small_d_16 gen_random n=100000 d=180 impossible=1
tc m2
tc m4

group group3 30
limits nMax=100000 dMax=364
include_group group1
include_group group2
tc full_1 gen_random n=50 d=300
tc full_2 gen_random n=50 d=300
tc full_3 gen_random n=50 d=330
tc full_4 gen_random n=50 d=330 impossible=1
tc full_5 gen_random n=200 d=350
tc full_6 gen_random n=200 d=350 impossible=1
tc full_7 gen_random n=500 d=300
tc full_8 gen_random n=1000 d=350
tc full_9 gen_random n=5000 d=250
tc full_10 gen_random n=5000 d=360
tc full_11 gen_random n=50000 d=363
tc full_12 gen_random n=100000 d=363
tc full_13 gen_random n=100000 d=363 impossible=1
tc full_14 gen_random n=100000 d=364
tc full_15 gen_random n=100000 d=364 impossible=1
tc full_16 gen_structured n=90000 d=340
tc full_17 gen_structured n=95000 d=341
tc full_18 gen_structured n=99999 d=350
tc full_19 gen_structured n=99999 d=360
tc full_20 gen_structured n=99999 d=363
tc full_21 gen_bign n=99998 d=350
tc full_22 gen_bign n=99999 d=360
tc full_23 gen_bign n=100000 d=362
tc full_24 gen_few n=98765 k=2
tc full_25 gen_few n=100000 k=2
tc full_26 gen_few n=99999 k=8
tc full_27 gen_few n=99999 k=12
tc full_28 gen_few n=99999 k=25
tc full_29 gen_few n=100000 k=33
