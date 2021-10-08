#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution fredrik.cpp

compile gen_random.py
compile gen_smart.py pypy
compile gen_fixed.py

samplegroup
limits nMax=-1
sample 1
sample 2
sample 3

group group1 20
limits nMax=-1
tc poster gen_fixed s=VBBBVVBVBBVBVVBBVV

group group2 40
limits nMax=1000
include_group group1
tc 1
tc 2
tc 3
tc small-smart-9 gen_smart n=1000 ans=500
tc small-ans-first-half gen_fixed s=BBBVBVBBBBVVVVVVVBVV
tc small-short-1 gen_fixed s=VB
tc small-short-2 gen_fixed s=BV
tc small-short-3 gen_fixed s=BB
tc small-short-4 gen_fixed s=VV
tc small-rand-2 gen_random n=10 r=0
tc small-rand-3 gen_random n=10 r=0.5
tc small-rand-4 gen_random n=10 r=1
tc small-rand-5 gen_random n=100 r=0.5
tc small-rand-6 gen_random n=800 r=0.01
tc small-rand-7 gen_random n=800 r=0.1
tc small-rand-8 gen_random n=800 r=0.5
tc small-rand-9 gen_random n=800 r=0.99
tc small-rand-10 gen_random n=1000 r=0.01
tc small-rand-11 gen_random n=1000 r=0.1
tc small-rand-12 gen_random n=1000 r=0.5
tc small-rand-13 gen_random n=1000 r=0.99
tc small-smart-1 gen_smart n=800 ans=2
tc small-smart-2 gen_smart n=800 ans=100
tc small-smart-3 gen_smart n=800 ans=300
tc small-smart-4 gen_smart n=800 ans=390
tc small-smart-5 gen_smart n=1000 ans=10
tc small-smart-6 gen_smart n=1000 ans=100
tc small-smart-7 gen_smart n=1000 ans=200
tc small-smart-8 gen_smart n=1000 ans=450


group group3 40
limits nMax=1000000
include_group group2

tc big-rand-1 gen_random n=1000000 r=0.01
tc big-rand-2 gen_random n=1000000 r=0.1
tc big-rand-3 gen_random n=1000000 r=0.5
tc big-rand-4 gen_random n=1000000 r=0.99
tc big-smart-1 gen_smart n=1000000 ans=10
tc big-smart-2 gen_smart n=1000000 ans=100
tc big-smart-3 gen_smart n=1000000 ans=10000
tc big-smart-4 gen_smart n=1000000 ans=100000
tc big-smart-5 gen_smart n=1000000 ans=200000
tc big-smart-6 gen_smart n=1000000 ans=450000
tc big-smart-7 gen_smart n=1000000 ans=500000
