#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution eae.py python2

compile gen_random.py

samplegroup
limits maxN=10 maxM=10 maxT=10
sample 1
sample 2
sample 3

group group1 20
limits maxN=100 maxM=100 maxT=100
include_group sample
tc small-spec-1 gen_random maxN=1 maxM=100 maxT=100
tc small-spec-2 gen_random maxN=100 maxM=1 maxT=100
tc small-spec-3 gen_random maxN=100 maxM=100 maxT=1
tc small-rand-1 gen_random maxN=100 maxM=100 maxT=100
tc small-rand-2 gen_random maxN=100 maxM=100 maxT=100
tc small-rand-3 gen_random maxN=100 maxM=100 maxT=100
tc small-rand-4 gen_random minN=50 maxN=100 maxM=n maxT=100
tc small-rand-5 gen_random minN=50 maxN=100 maxM=n maxT=100
tc small-rand-6 gen_random minN=50 maxN=100 maxM=n maxT=100

group group2 30
include_group group1
limits maxN=1000 maxM=1000 maxT=1000
tc med-rand-1 gen_random minN=500 maxN=1000 minM=500 maxM=1000 minT=500 maxT=1000
tc med-rand-2 gen_random minN=500 maxN=1000 minM=500 maxM=1000 minT=500 maxT=1000
tc med-rand-3 gen_random minN=500 maxN=1000 minM=500 maxM=1000 minT=500 maxT=1000
tc med-rand-4 gen_random minN=500 maxN=1000 maxM=n minT=500 maxT=1000
tc med-rand-5 gen_random minN=500 maxN=1000 maxM=n minT=500 maxT=1000
tc med-rand-6 gen_random minN=500 maxN=1000 maxM=n minT=500 maxT=1000

group group3 25
include_group group2
limits maxN=1000 maxM=1000 maxT=1000000000
tc bigt-rand-1 gen_random minN=500 maxN=1000 minM=500 maxM=1000 minT=1000 maxT=1000000000
tc bigt-rand-2 gen_random minN=500 maxN=1000 minM=500 maxM=1000 minT=1000 maxT=1000000000
tc bigt-rand-3 gen_random minN=500 maxN=1000 minM=500 maxM=1000 minT=1000 maxT=1000000000
tc bigt-rand-4 gen_random minN=500 maxN=1000 maxM=n minT=1000 maxT=1000000000
tc bigt-rand-5 gen_random minN=500 maxN=1000 maxM=n minT=1000 maxT=1000000000
tc bigt-rand-6 gen_random minN=500 maxN=1000 maxM=n minT=1000 maxT=1000000000
tc bigt-rand-7 gen_random minN=900 maxN=1000 minM=900 maxM=1000 minT=100000000 maxT=1000000000

group group4 25
include_group group3
limits maxN=200000 maxM=200000 maxT=1000000000
tc big-rand-1 gen_random minN=1000 maxN=200000 minM=1000 maxM=200000 minT=1000 maxT=1000000000
tc big-rand-2 gen_random minN=1000 maxN=200000 minM=1000 maxM=200000 minT=1000 maxT=1000000000
tc big-rand-3 gen_random minN=1000 maxN=200000 minM=1000 maxM=200000 minT=1000 maxT=1000000000
tc big-rand-4 gen_random minN=100000 maxN=200000 maxM=n minT=1000 maxT=1000000000
tc big-rand-5 gen_random minN=100000 maxN=200000 maxM=n minT=1000 maxT=1000000000
tc big-rand-6 gen_random minN=100000 maxN=200000 maxM=n minT=1000 maxT=1000000000
tc big-rand-7 gen_random minN=199900 maxN=200000 minM=199900 maxM=200000 minT=100000000 maxT=1000000000
tc big-rand-8 gen_random minN=199900 maxN=200000 minM=199900 maxM=200000 minT=100000000 maxT=1000000000
