#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution ng.cpp

compile gen_random.py
compile gen_special.py
compile gen_cases.py

MAXN=200000
MAXQ=100000

samplegroup
limits nMax=$MAXN kMax=$MAXN qMax=$MAXQ special=none
sample 1


group group1 9
limits nMax=15 kMax=15 qMax=15 special=none
tc 1
tc tiny-01 gen_random n=4 k=2 q=5
tc tiny-02 gen_random n=11 k=3 q=15
tc tiny-03 gen_random n=13 k=5 q=15
tc tiny-04 gen_random n=15 k=4 q=15
tc tiny-05 gen_random n=15 k=3 q=15
tc tiny-06 gen_random n=15 k=5 q=15
tc tiny-07 gen_random n=15 k=13 q=15
tc tiny-08 gen_random n=15 k=15 q=15
tc tiny-09 gen_random n=1 k=1 q=1
tc tiny-10 gen_random n=15 k=1 q=1
tc tiny-11 gen_random n=15 k=5 q=15 mode=smart
tc tiny-12 gen_random n=15 k=3 q=15 intervals=same
tc tiny-13 gen_special

group group2 11
limits nMax=100 kMax=100 qMax=100 special=none
include_group group1
tc small-01 gen_random n=20 k=7 q=45
tc small-02 gen_random n=30 k=7 q=45
tc small-03 gen_random n=75 k=13 q=100
tc small-04 gen_random n=100 k=21 q=100
tc small-05 gen_random n=100 k=3 q=100
tc small-06 gen_random n=100 k=13 q=100
tc small-07 gen_random n=100 k=100 q=100
tc small-08 gen_random n=100 k=25 q=100 intervals=same
tc small-09 gen_random n=100 k=5 q=100 mode=manyzeros x=65
tc small-10 gen_random n=100 k=3 q=100 mode=manyzeros x=98
tc small-11 gen_random n=100 k=10 q=100 mode=smart
tc small-12 gen_random n=100 k=30 q=100 mode=smart

group group3 17
limits nMax=1000 kMax=1000 qMax=1000 special=none
include_group group2
tc medium-01 gen_random n=300 k=11 q=211
tc medium-02 gen_random n=600 k=101 q=713
tc medium-03 gen_random n=999 k=31 q=1000
tc medium-04 gen_random n=1000 k=2 q=1000
tc medium-05 gen_random n=1000 k=20 q=1000
tc medium-06 gen_random n=1000 k=30 q=1000
tc medium-07 gen_random n=1000 k=500 q=1000
tc medium-08 gen_random n=1000 k=999 q=1000 intervals=same
tc medium-09 gen_random n=1000 k=100 q=1000 intervals=small
tc medium-10 gen_random n=1000 k=100 q=1000 mode=manyzeros x=800
tc medium-11 gen_random n=1000 k=37 q=1000 mode=smart
tc medium-12 gen_random n=1000 k=139 q=1000 mode=smart
tc medium-13 gen_random n=1000 k=300 q=1000 mode=smart

group group4 5
limits nMax=$MAXN kMax=1 qMax=$MAXQ special=none
tc k1-01 gen_random n=1 k=1 q=1
tc k1-02 gen_random n=$MAXN k=1 q=$MAXQ
tc k1-03 gen_random n=$MAXN k=1 q=$MAXQ intervals=same
tc k1-04 gen_random n=$((MAXN-1)) k=1 q=$MAXQ intervals=same

group group5 7
limits nMax=$MAXN kMax=2 qMax=$MAXQ special=ktwo
tc k2-01 gen_random n=2 k=2 q=1
tc k2-02 gen_random n=13 k=2 q=100
tc k2-03 gen_random n=$MAXN k=2 q=$MAXQ
tc k2-04 gen_random n=$MAXN k=2 q=$MAXQ mode=manyzeros x=$((MAXN-4))

group group6 11
limits nMax=$MAXN kMax=$MAXN qMax=$MAXQ special=small_intervals
tc small_intervals-01 gen_random n=10 k=4 q=13 intervals=small
tc small_intervals-02 gen_random n=100 k=20 q=100 intervals=small
tc small_intervals-03 gen_random n=100 k=60 q=100 intervals=small
tc small_intervals-04 gen_random n=15000 k=2000 q=15000 intervals=small
tc small_intervals-05 gen_random n=15000 k=2000 q=15000 mode=smart intervals=small
tc small_intervals-06 gen_random n=15000 k=7000 q=15000 mode=smart intervals=small
tc small_intervals-07 gen_random n=$MAXN k=$((MAXN/10)) q=$MAXQ mode=smart intervals=small
tc small_intervals-08 gen_random n=$MAXN k=$((MAXN-1)) q=$MAXQ mode=double intervals=same x=0
tc small_intervals-09 gen_random n=$MAXN k=3 q=$MAXQ mode=manyzeros intervals=small x=$((MAXN/2))

group group7 23
limits nMax=$MAXN kMax=$MAXN qMax=1 special=full
tc q1-01 gen_random n=4000 k=100 q=1 intervals=same
tc q1-02 gen_random n=7000 k=1001 q=1 intervals=same
tc q1-03 gen_random n=15000 k=10 q=1 intervals=same
tc q1-04 gen_random n=15000 k=3 q=1 intervals=same
tc q1-05 gen_random n=15000 k=2 q=1 intervals=same
tc q1-06 gen_random n=15000 k=1 q=1 intervals=same
tc q1-07 gen_random n=15000 k=14000 q=1 intervals=same
tc q1-08 gen_random n=15000 k=1000 q=1 mode=smart intervals=same
tc q1-09 gen_random n=20000 k=10000 q=1 mode=double intervals=same x=5000
tc q1-10 gen_random n=20000 k=1000 q=1 mode=double intervals=same x=5000
tc q1-11 gen_random n=20000 k=100 q=1 mode=double intervals=same x=5000
tc q1-12 gen_random n=20000 k=10 q=1 mode=double intervals=same x=5000
tc q1-13 gen_random n=20000 k=3 q=1 mode=double intervals=same x=5000
tc q1-14 gen_random n=20000 k=1000 q=1 mode=double intervals=same x=0
tc q1-15 gen_random n=20000 k=19999 q=1 intervals=same
tc q1-16 gen_random n=$MAXN k=10 q=1 mode=double intervals=same x=$((MAXN/4))
tc q1-17 gen_random n=$MAXN k=1000 q=1 mode=double intervals=same x=$((MAXN/4))
tc q1-18 gen_random n=$MAXN k=50000 q=1 mode=double intervals=same x=$((MAXN/4))
tc q1-19 gen_random n=$MAXN k=$MAXN q=1 intervals=same
tc q1-20 gen_random n=$MAXN k=1000 q=1 intervals=same
tc q1-21 gen_random n=$MAXN k=1000 q=1 mode=manyzeros intervals=same x=$((MAXN/2))
tc q1-22 gen_random n=$MAXN k=$((MAXN/10)) q=1 mode=smart intervals=same
tc q1-23 gen_special q=1
tc q1-24 gen_cases n=50000 left=0 right=0
tc q1-25 gen_cases n=50000 left=0 right=1
tc q1-26 gen_cases n=50000 left=1 right=0
tc q1-27 gen_cases n=50000 left=1 right=1

group group8 17
limits nMax=$MAXN kMax=$MAXN qMax=$MAXQ special=none
include_group group3
include_group group4
include_group group5
include_group group6
include_group group7
tc large-01 gen_random n=5000 k=100 q=2000
tc large-02 gen_random n=25000 k=100 q=25000
tc large-03 gen_random n=25000 k=1000 q=25000
tc large-04 gen_random n=25000 k=10000 q=25000
tc large-05 gen_random n=25000 k=100 q=25000 mode=double x=7000
tc large-06 gen_random n=25000 k=1000 q=25000 mode=double x=7000
tc large-07 gen_random n=25000 k=100 q=25000 mode=double intervals=symmetric x=7000
tc large-08 gen_random n=25000 k=1000 q=25000 mode=double intervals=symmetric x=7000
tc large-09 gen_random n=$MAXN k=10 q=$MAXQ mode=double intervals=symmetric x=$((MAXN/4))
tc large-10 gen_random n=$MAXN k=100 q=$MAXQ mode=double intervals=symmetric x=$((MAXN/4))
tc large-11 gen_random n=$MAXN k=10000 q=$MAXQ mode=double intervals=symmetric x=$((MAXN/4))
tc large-12 gen_random n=$MAXN k=1000 q=$MAXQ mode=double x=$((MAXN/4))
tc large-13 gen_random n=$MAXN k=10 q=$MAXQ
tc large-14 gen_random n=$MAXN k=1000 q=$MAXQ
tc large-15 gen_random n=$MAXN k=10000 q=$MAXQ
tc large-16 gen_random n=$MAXN k=$((MAXN/2)) q=$MAXQ
tc large-17 gen_random n=$MAXN k=1000 q=$MAXQ mode=double intervals=same x=0
tc large-18 gen_random n=$MAXN k=30000 q=$MAXQ mode=smart
tc large-19 gen_random n=$MAXN k=$MAXN q=$MAXQ intervals=same
tc large-20 gen_random n=$MAXN k=3000 q=$MAXQ mode=smart
