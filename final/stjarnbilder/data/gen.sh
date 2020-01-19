#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution eae_vector.cpp opt

compile gen_random.py
compile gen_structured.py

samplegroup
limits nMax=1000
sample 1
sample 2
sample 3

group group1 24
limits nMax=1000 ansMax=1
tc 1
tc_manual ../manual_tests/stop_wa_sort.in
tc small_ans_1 gen_random n=1    planeCount=0
tc small_ans_2 gen_random n=2    planeCount=0
tc small_ans_3 gen_random n=500  planeCount=0
tc small_ans_4 gen_random n=983  planeCount=0
tc small_ans_5 gen_random n=1000 planeCount=0
tc small_ans_6 gen_random n=2    planeCount=1
tc small_ans_7 gen_random n=500  planeCount=1
tc small_ans_8 gen_random n=1000 planeCount=1
tc small_ans_9 gen_random n=1000 planeCount=1
tc small_ans_structured1 gen_structured n=1000 k=0 delta=1,0
tc small_ans_structured2 gen_structured n=1000 k=1 delta=37,-40

group group2 39
limits nMax=200
tc 2
tc 3
tc stop_wa_sort
tc small_ans_1
tc small_ans_2
tc small_ans_6
tc cubic_fewstars gen_random n=200 starCount=1
tc cubic_1 gen_random n=1
tc cubic_2 gen_random n=2
tc cubic_3 gen_random n=10
tc cubic_4 gen_random n=20 planeCount=1
tc cubic_5 gen_random n=100
tc cubic_6 gen_random n=150 planeCount=0
tc cubic_7 gen_random n=200 planeCount=1
tc cubic_8 gen_random n=200
tc cubic_9 gen_random n=200
tc cubic_fewstars_2 gen_random n=200 starCount=2
tc cubic_fewstars_3 gen_random n=200 starCount=6
tc cubic_structured1 gen_structured n=200 k=10 delta=1,1
tc cubic_structured2 gen_structured n=200 k=10 delta=67,0

group group3 37
limits nMax=1000
include_group group1
include_group group2
tc fewstars gen_random n=1000 starCount=1
tc full_1 gen_random n=577
tc full_2 gen_random n=999
tc full_3 gen_random n=1000
tc full_4 gen_random n=1000
tc full_5 gen_random n=1000
tc full_6 gen_random n=1000
tc fewstars_2 gen_random n=1000 starCount=3
tc fewstars_3 gen_random n=1000 starCount=5
tc full_structured1 gen_structured n=1000 k=10 delta=39,37
