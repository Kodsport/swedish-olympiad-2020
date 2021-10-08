#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution fe.cpp

compile gen_random.py
compile gen_antiquad.py

MAXN=200000
MAXM=200000

samplegroup
limits nMax=$MAXN mMax=$MAXM onlyForward=0
sample 1
sample 2


group group1 8
limits nMax=10 mMax=10 onlyForward=1
tc 1
tc g1-01 gen_random n=1 m=2 onlyForward=True
tc g1-02 gen_random n=4 m=2 onlyForward=True
tc g1-03 gen_random n=4 m=5 onlyForward=True
tc g1-04 gen_random n=1 m=10 onlyForward=True
tc g1-05 gen_random n=4 m=10 onlyForward=True
tc g1-06 gen_random n=10 m=10 onlyForward=True
tc g1-07 gen_random n=10 m=10 onlyForward=True
tc g1-08 gen_random n=10 m=10 onlyForward=True
tc g1-09 gen_random n=10 m=10 onlyForward=True

group group2 13
limits nMax=1000 mMax=1000 onlyForward=1
include_group group1
tc g2-01 gen_random n=20 m=20 onlyForward=True
tc g2-02 gen_random n=200 m=200 onlyForward=True
tc g2-03 gen_random n=567 m=567 onlyForward=True
tc g2-04 gen_random n=1 m=1000 onlyForward=True
tc g2-05 gen_random n=2 m=1000 onlyForward=True
tc g2-06 gen_random n=10 m=1000 onlyForward=True
tc g2-07 gen_random n=50 m=1000 onlyForward=True
tc g2-08 gen_random n=200 m=1000 onlyForward=True
tc g2-09 gen_random n=1000 m=1000 onlyForward=True
tc g2-10 gen_random n=1000 m=1000 onlyForward=True
tc g2-11 gen_random n=1000 m=1000 onlyForward=True
tc g2-12 gen_random n=1000 m=1000 onlyForward=True

group group3 40
limits nMax=$MAXN mMax=$MAXM onlyForward=1
include_group group2
tc g3-02 gen_random n=2000 m=10000 onlyForward=True
tc g3-03 gen_random n=10000 m=23451 onlyForward=True
tc g3-04 gen_random n=10 m=200000 onlyForward=True
tc g3-05 gen_random n=100 m=200000 onlyForward=True
tc g3-06 gen_random n=2000 m=200000 onlyForward=True
tc g3-07 gen_random n=10000 m=200000 onlyForward=True
tc g3-08 gen_random n=80000 m=200000 onlyForward=True
tc g3-09 gen_random n=200000 m=200000 onlyForward=True
tc g3-10 gen_random n=200000 m=200000 onlyForward=True
tc g3-11 gen_random n=200000 m=200000 onlyForward=True
tc g3-12 gen_random n=200000 m=200000 onlyForward=True
tc g3-13 gen_antiquad n=200000 m=200000
tc g3-14 gen_antiquad n=200000 m=200000

group group4 15
limits nMax=1000 mMax=1000 onlyForward=0
include_group group2
tc 2
tc g4-01 gen_random n=20 m=20 onlyForward=False
tc g4-02 gen_random n=200 m=200 onlyForward=False
tc g4-03 gen_random n=567 m=567 onlyForward=False
tc g4-04 gen_random n=1 m=1000 onlyForward=False
tc g4-05 gen_random n=2 m=1000 onlyForward=False
tc g4-06 gen_random n=10 m=1000 onlyForward=False
tc g4-07 gen_random n=50 m=1000 onlyForward=False
tc g4-08 gen_random n=200 m=1000 onlyForward=False
tc g4-09 gen_random n=1000 m=1000 onlyForward=False
tc g4-10 gen_random n=1000 m=1000 onlyForward=False
tc g4-11 gen_random n=1000 m=1000 onlyForward=False
tc g4-12 gen_random n=1000 m=1000 onlyForward=False

group group5 24
limits nMax=$MAXN mMax=$MAXM onlyForward=0
include_group group3
include_group group4
tc g5-02 gen_random n=2000 m=10000 onlyForward=False
tc g5-03 gen_random n=10000 m=23451 onlyForward=False
tc g5-04 gen_random n=10 m=200000 onlyForward=False
tc g5-05 gen_random n=100 m=200000 onlyForward=False
tc g5-06 gen_random n=2000 m=200000 onlyForward=False
tc g5-07 gen_random n=10000 m=200000 onlyForward=False
tc g5-08 gen_random n=80000 m=200000 onlyForward=False
tc g5-09 gen_random n=200000 m=200000 onlyForward=False
tc g5-10 gen_random n=200000 m=200000 onlyForward=False
tc g5-11 gen_random n=200000 m=200000 onlyForward=False
tc g5-12 gen_random n=200000 m=200000 onlyForward=False
