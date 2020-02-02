#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution shortest.cpp

compile gen.py
compile gen_alternating.py
compile gen_segment.py
compile gen_invalid.py
compile gen_antibug.py
compile gen_different.py

MAXN=1000

samplegroup
limits nMax=$MAXN lMax=26 kMax=1
sample 1
sample 2
sample 3

group group1 7
limits nMax=$MAXN lMax=1 kMax=0
tc one-letter-01 gen l1=5 l2=5 letters=1 k=0
tc one-letter-02 gen l1=55 l2=55 letters=1 k=0
tc one-letter-03 gen l1=55 l2=5 letters=1 k=0
tc one-letter-04 gen l1=5 l2=55 letters=1 k=0
tc one-letter-05 gen l1=55 l2=55 letters=1 yes=1 k=0
tc one-letter-06 gen l1=$MAXN l2=$MAXN letters=1 k=0
tc one-letter-07 gen l1=$MAXN l2=$((MAXN/2)) letters=1 k=0
tc one-letter-08 gen l1=$MAXN l2=$((MAXN/2)) letters=1 k=0
tc one-letter-09 gen l1=$MAXN l2=$((MAXN/3)) letters=1 yes=1 k=0
tc one-letter-10 gen l1=$MAXN l2=$((MAXN-1)) letters=1 yes=1 k=0
tc one-letter-11 gen l1=$MAXN l2=1 letters=1 k=0
tc one-letter-12 gen l1=1 l2=1 letters=1 k=0
tc one-letter-13 gen_invalid l1=$MAXN l2=$((MAXN/2)) letters=1 k=0
tc one-letter-14 gen_antibug l1=2 k=0
tc one-letter-15 gen_antibug l1=52 kind=1 k=0

group group2 30
limits nMax=$MAXN lMax=26 kMax=0
include_group group1
tc 1
tc 2
tc non-optimal-01 gen l1=1 l2=1 yes=1 k=0
tc non-optimal-02 gen l1=$MAXN l2=1 yes=1 k=0
tc non-optimal-03 gen l1=$MAXN l2=$MAXN k=0
tc non-optimal-04 gen l1=$MAXN l2=$((MAXN/2)) k=0
tc non-optimal-05 gen l1=$MAXN l2=$MAXN yes=1 k=0
tc non-optimal-06 gen l1=$MAXN l2=$((MAXN/2)) yes=1 k=0
tc non-optimal-07 gen l1=$MAXN l2=$((MAXN/2)) yes=1 k=0
tc non-optimal-08 gen l1=$MAXN l2=$((MAXN/3)) yes=1 k=0 letters=2
tc non-optimal-09 gen l1=$MAXN l2=5 yes=1 k=0
tc non-optimal-10 gen l1=$((MAXN-1)) l2=$MAXN yes=1 k=0
tc non-optimal-11 gen l1=$MAXN l2=$((MAXN/2)) yes=1 k=0
tc non-optimal-12 gen_alternating l1=$MAXN l2=$((MAXN/2)) letters=2 yes=1 k=0
tc non-optimal-13 gen_alternating l1=$MAXN l2=$((MAXN/3)) letters=3 yes=1 k=0
tc non-optimal-14 gen_segment l1=$MAXN l2=$((MAXN/2)) letters=2 yes=1 k=0
tc non-optimal-15 gen_segment l1=$MAXN l2=$((MAXN/2)) letters=4 yes=1 k=0
tc non-optimal-16 gen_segment l1=10 l2=$MAXN letters=26 yes=1 k=0
tc non-optimal-17 gen_invalid l1=$MAXN l2=$((MAXN-1)) k=0
tc non-optimal-18 gen_invalid l1=$MAXN l2=$((MAXN/2)) k=0
tc non-optimal-19 gen_invalid l1=$((MAXN-1)) l2=$MAXN k=0

group group3 11
limits nMax=5 lMax=2 kMax=1
tc small-01 gen l1=1 l2=1 letters=2
tc small-02 gen l1=5 l2=5 letters=2
tc small-03 gen l1=5 l2=3 letters=2
tc small-04 gen l1=5 l2=3 letters=2
tc small-05 gen l1=5 l2=4 letters=2
tc small-06 gen l1=5 l2=4 letters=2
tc small-07 gen l1=5 l2=2 letters=2
tc small-08 gen l1=5 l2=3 letters=2 yes=1
tc small-09 gen l1=5 l2=4 letters=2 yes=1
tc small-10 gen l1=5 l2=5 letters=2 yes=1
tc small-11 gen l1=5 l2=2 letters=2 yes=1
tc small-12 gen l1=5 l2=3 letters=2 yes=1
tc small-13 gen_alternating l1=5 l2=3 letters=2 yes=1
tc small-14 gen_alternating l1=5 l2=5 letters=2
tc small-15 gen_invalid l1=5 l2=3 letters=2
tc small-16 gen_invalid l1=5 l2=3 letters=2
tc small-17 gen_invalid l1=5 l2=3 letters=2
tc small-18 gen_invalid l1=5 l2=3 letters=2
tc small-19 gen_antibug l1=3
tc small-20 gen_antibug l1=5 kind=1
tc_manual ../manual_tests/anti_jb.in
tc_manual ../manual_tests/big_g3.in

group group4 15
limits nMax=50 lMax=26 kMax=1
include_group group3
tc 3
tc medium-01 gen l1=50 l2=1
tc medium-02 gen l1=50 l2=1 yes=1
tc medium-03 gen l1=50 l2=50
tc medium-04 gen l1=50 l2=25
tc medium-05 gen l1=50 l2=50 yes=1
tc medium-06 gen l1=50 l2=12 yes=1
tc medium-07 gen l1=50 l2=17 yes=1 letters=4
tc medium-08 gen l1=25 l2=50 yes=1 letters=3
tc medium-09 gen l1=50 l2=33 yes=1 letters=2
tc medium-10 gen l1=50 l2=41 yes=1
tc medium-11 gen l1=49 l2=50 yes=1
tc medium-12 gen_alternating l1=50 l2=25 letters=2 yes=1
tc medium-13 gen_alternating l1=50 l2=16 letters=3 yes=1
tc medium-14 gen_segment l1=50 l2=25 letters=4 yes=1
tc medium-15 gen_invalid l1=50 l2=41
tc medium-16 gen_invalid l1=35 l2=41
tc medium-17 gen_invalid l1=4 l2=33
tc medium-18 gen_invalid l1=23 l2=50
tc medium-19 gen_different l1=50 l2=13 letters=2 yes=1
tc medium-20 gen_different l1=7 l2=50 letters=4 yes=1
tc_manual ../manual_tests/zzz.in


group group5 17
limits nMax=200 lMax=26 kMax=1
include_group group4
tc bigger-01 gen l1=200 l2=1
tc bigger-02 gen l1=200 l2=1 yes=1
tc bigger-03 gen l1=200 l2=200
tc bigger-04 gen l1=200 l2=100
tc bigger-05 gen l1=200 l2=200 yes=1
tc bigger-06 gen l1=200 l2=12 yes=1
tc bigger-07 gen l1=200 l2=75 yes=1
tc bigger-08 gen l1=200 l2=100 yes=1
tc bigger-09 gen l1=200 l2=100 yes=1 letters=5
tc bigger-10 gen l1=187 l2=200 yes=1 letters=3
tc bigger-11 gen l1=199 l2=200 yes=1 letters=2
tc bigger-12 gen_alternating l1=200 l2=100 letters=2 yes=1
tc bigger-13 gen_alternating l1=200 l2=34 letters=3 yes=1
tc bigger-14 gen_segment l1=200 l2=100 letters=4 yes=1
tc bigger-15 gen_invalid l1=200 l2=189
tc bigger-16 gen_invalid l1=167 l2=198
tc bigger-17 gen_invalid l1=17 l2=157
tc bigger-18 gen_invalid l1=97 l2=200
tc bigger-19 gen_different l1=200 l2=34 letters=3 yes=1

group group6 20
limits nMax=$MAXN lMax=26 kMax=1
include_group group5
include_group group2
tc large-01 gen l1=$MAXN l2=1
tc large-02 gen l1=$MAXN l2=1 yes=1
tc large-03 gen l1=$MAXN l2=$MAXN
tc large-04 gen l1=$MAXN l2=$((MAXN/2))
tc large-05 gen l1=$MAXN l2=$MAXN yes=1
tc large-06 gen l1=$MAXN l2=$((MAXN/2)) yes=1
tc large-07 gen l1=$MAXN l2=$((MAXN/2)) yes=1 letters=4
tc large-08 gen l1=$MAXN l2=$((MAXN/3)) yes=1
tc large-09 gen l1=$MAXN l2=5 yes=1
tc large-10 gen l1=$((MAXN-1)) l2=$MAXN yes=1
tc large-11 gen l1=$MAXN l2=$((MAXN/2)) yes=1
tc large-12 gen_alternating l1=$MAXN l2=$((MAXN/2)) letters=2 yes=1
tc large-13 gen_alternating l1=$MAXN l2=$((MAXN/3)) letters=3 yes=1
tc large-14 gen_segment l1=$MAXN l2=$((MAXN/2)) letters=2 yes=1
tc large-15 gen_segment l1=$MAXN l2=$((MAXN/2)) letters=4 yes=1
tc large-16 gen_segment l1=10 l2=$MAXN letters=26 yes=1
tc large-17 gen_invalid l1=$MAXN l2=$((MAXN-1))
tc large-18 gen_invalid l1=$MAXN l2=$((MAXN/2))
tc large-19 gen_invalid l1=$((MAXN-1)) l2=$MAXN
tc large-20 gen l1=$MAXN l2=$((MAXN/2)) yes=1 letters=2
tc large-21 gen_different l1=$MAXN l2=300 letters=2 yes=1
tc large-22 gen_different l1=$MAXN l2=30 letters=5 yes=1