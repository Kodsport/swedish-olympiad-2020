#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_random.py
compile gen_nom.py

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits maxn=10 maxk=5 maxm=0
tc 2
tc_manual g1
for n in {2..10};
do
  for m in {2..5};
  do
    tc g1-exact-$n-$m gen_nom maxn=$n maxk=$m
  done
done

group g2 40
limits maxn=10 maxk=5
include_group g1
tc 1
tc 2
tc_manual g2
tc_manual g3
tc g2-rand-01 gen_random maxn=10 maxk=5
tc g2-rand-02 gen_random maxn=10 maxk=5 
tc g2-rand-03 gen_random maxn=10 maxk=5
tc g2-rand-04 gen_random maxn=10 maxk=5 
tc g2-rand-05 gen_random maxn=10 maxk=5
tc g2-rand-06 gen_random maxn=10 maxk=5 
tc g2-rand-07 gen_random maxn=10 maxk=5 
tc g2-rand-08 gen_random maxn=10 maxk=5 

group g3 20
limits maxm=1
include_group g1
tc 2
tc_manual g4
tc g3-rand-01 gen_random maxm=1 
tc g3-rand-02 gen_random maxm=1
tc g3-rand-03 gen_random maxm=1
tc g3-rand-04 gen_random maxm=1
tc g3-rand-05 gen_random maxm=1
tc g3-rand-06 gen_random maxm=1
tc g3-rand-07 gen_random maxm=1
tc g3-rand-08 gen_random maxm=1

group g4 20
include_group g1
include_group g2
include_group g3
tc 1
tc 2
tc 3
tc_manual g5
tc g4-rand-01 gen_random 
tc g4-rand-02 gen_random 
tc g4-rand-03 gen_random 
tc g4-rand-04 gen_random 
tc g4-rand-05 gen_random 
tc g4-rand-06 gen_random 
tc g4-rand-07 gen_random
tc g4-rand-08 gen_random 
