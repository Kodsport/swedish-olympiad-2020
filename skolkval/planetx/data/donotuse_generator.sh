#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution fe100.cpp

compile gen_random.py
compile gen_empty.py

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits n=1
tc 2
tc_manual g1

tc empty-row gen_empty n=1 m=10
tc randr-01 gen_random maxn=1 dens=20
tc randr-02 gen_random maxn=1 dens=20
tc randr-03 gen_random maxn=1 dens=20
tc randr-04 gen_random maxn=1 dens=20
tc randr-05 gen_random maxn=1 dens=20
tc randr-06 gen_random maxn=1 dens=30
tc randr-07 gen_random maxn=1 dens=30
tc randr-08 gen_random maxn=1 dens=30
tc randr-09 gen_random maxn=1 dens=50
tc randr-10 gen_random maxn=1 dens=50


group g2 20
limits n=3 m=3
tc 1
tc_manual g2

tc empty-small gen_empty n=3 m=3
tc rands-01 gen_random maxn=3 maxm=3 dens=20
tc rands-02 gen_random maxn=3 maxm=3 dens=20
tc rands-03 gen_random maxn=3 maxm=3 dens=20
tc rands-04 gen_random maxn=3 maxm=3 dens=20
tc rands-05 gen_random maxn=3 maxm=3 dens=20
tc rands-06 gen_random maxn=3 maxm=3 dens=30
tc rands-07 gen_random maxn=3 maxm=3 dens=30
tc rands-08 gen_random maxn=3 maxm=3 dens=30
tc rands-09 gen_random maxn=3 maxm=3 dens=50
tc rands-10 gen_random maxn=3 maxm=3 dens=50

group g3 60
include_group g1
include_group g2
tc 3
tc_manual g3
tc_manual g4
tc_manual g5

tc empty-big gen_empty n=10 m=10
tc rand-01 gen_random dens=5
tc rand-02 gen_random dens=5
tc rand-03 gen_random dens=5
tc rand-04 gen_random dens=10
tc rand-05 gen_random dens=10
tc rand-06 gen_random dens=10
tc rand-07 gen_random dens=10
tc rand-08 gen_random dens=20
tc rand-09 gen_random dens=20
tc rand-10 gen_random dens=20
