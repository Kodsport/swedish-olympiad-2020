#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution simonk.cpp

compile gen_random.py
compile gen_smarter.py pypy
compile gen_cheese.py

samplegroup
limits k=20 maxN=100 maxQ=100
sample 1

group group1 15
limits k=8 maxN=10 maxQ=10
tc 1
tc g1-01 gen_random k=8 n=10 q=10
tc g1-02 gen_random k=8 n=10 q=10
tc g1-03 gen_random k=8 n=10 q=10
tc g1-04 gen_random k=8 n=10 q=10
tc g1-05 gen_random k=8 n=10 q=10
tc g1-06 gen_random k=7 n=10 q=10
tc g1-07 gen_random k=6 n=10 q=10
tc g1-08 gen_random k=5 n=10 q=10
tc g1-09 gen_random k=4 n=10 q=10
tc g1-10 gen_random k=8 n=10 q=10
tc g1-11 gen_random k=1 n=2 q=10
tc g1-smart gen_smarter n=10 q=10 k=8 mode=1
tc g1-manyimp gen_smarter n=10 q=10 k=8 mode=2

group group2 30
limits k=21 maxN=1000 maxQ=1000
include_group group1
tc g2-01 gen_random k=21 n=10 q=10
tc g2-02 gen_random k=21 n=100 q=100
tc g2-03 gen_random k=21 n=200 q=200
tc g2-04 gen_random k=21 n=300 q=300
tc g2-05 gen_random k=21 n=400 q=400
tc g2-06 gen_random k=21 n=500 q=1000
tc g2-07 gen_random k=21 n=750 q=500
tc g2-08 gen_random k=21 n=1000 q=500
tc g2-09 gen_random k=21 n=1000 q=1000
tc g2-10 gen_random k=21 n=1000 q=1000
tc g2-smart gen_smarter n=1000 q=1000 k=21 mode=1
tc g2-manyimp gen_smarter n=1000 q=1000 k=21 mode=2

group group3 55
limits k=21 maxN=200000 maxQ=200000
include_group group2
tc g3-smalln gen_random k=1 n=1 q=200000
tc g3-smart gen_smarter n=200000 q=200000 k=21 mode=1
tc g3-manyimp gen_smarter n=200000 q=200000 k=21 mode=2
tc g3-cheese gen_cheese
tc g3-rand gen_random k=21 n=200000 q=200000
tc g3-rand2 gen_random k=21 n=200000 q=200000
tc g3-smalln2 gen_random k=20 n=3 q=200000
tc g3-smart2 gen_smarter n=200000 q=200000 k=21 mode=1
tc g3-manyimp2 gen_smarter n=200000 q=200000 k=21 mode=2
