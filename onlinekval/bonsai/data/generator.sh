#!/bin/bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution MA.cpp

compile gen_BIG.py
compile gen_small_ans.py
compile gen_tall.py

samplegroup
limits n=10
sample 1
sample 2
sample 3

group group1 9
limits n=100000 restr=2 rooted=1
tc 1
tc simple-small1 gen_BIG n=10 mode=line rooted=1
tc simple-small2 gen_BIG n=11 mode=line rooted=1
tc simple-med1 gen_BIG n=9999 mode=line rooted=1
tc simple-med2 gen_BIG n=1000 mode=line rooted=1
tc simple-med3 gen_BIG n=1001 mode=line rooted=1
tc simple-med4 gen_BIG n=1002 mode=line rooted=1
tc simple-BIG1 gen_BIG n=99999 mode=line rooted=1
tc simple-BIG2 gen_BIG n=100000 mode=line rooted=1

group group2 11
limits n=100000 restr=3 rooted=1
include_group group1
tc 2
tc tall1 gen_tall n=11 rooted=1
tc tall2 gen_tall n=12 rooted=1
tc tall3 gen_tall n=1001 rooted=1
tc tall4 gen_tall n=1000 rooted=1
tc tall5 gen_tall n=10001 rooted=1
tc tall6 gen_tall n=10000 rooted=1
tc tall7 gen_tall n=100000 rooted=1
tc tall8 gen_tall n=100000 rooted=1
tc tall9 gen_tall n=100000 rooted=1
tc tall10 gen_tall n=45678 rooted=1
tc tall11 gen_tall n=34567 rooted=1
tc tall12 gen_tall n=98766 rooted=1

group group3 18
limits n=100000 restr=15 rooted=1
tc 1
tc 2
tc small_ans1 gen_small_ans maxt=9
tc small_ans2 gen_small_ans maxt=5
tc small_ans3 gen_small_ans maxt=14
tc small_ans4 gen_small_ans maxt=11
tc small_ans5 gen_small_ans maxt=13
tc small_ans6 gen_small_ans maxt=15
tc small_ans7 gen_small_ans maxt=15
tc small_ans8 gen_small_ans maxt=15
tc small_ans9 gen_small_ans maxt=15
tc small_ans10 gen_small_ans maxt=12
tc small_ans11 gen_small_ans maxt=13
tc small_ans12 gen_small_ans maxt=14

group group4 22
limits n=100000 rooted=1
include_group group2
include_group group3
include_group group4

tc RBIG-random1 gen_BIG n=50000 mode=random rooted=1
tc RBIG-random2 gen_BIG n=51000 mode=random rooted=1
tc RBIG-random3 gen_BIG n=99000 mode=random rooted=1
tc RBIG-random4 gen_BIG n=99000 mode=random rooted=1
tc RBIG-random5 gen_BIG n=100000 mode=random rooted=1
tc RBIG-random6 gen_BIG n=100000 mode=random rooted=1
tc RBIG-star1 gen_BIG n=51000 mode=star rooted=1
tc RBIG-star2 gen_BIG n=100000 mode=star rooted=1
tc RBIG-deep1 gen_BIG n=50000 mode=deep rooted=1
tc RBIG-deep2 gen_BIG n=99000 mode=deep rooted=1
tc RBIG-deep3 gen_BIG n=100000 mode=deep rooted=1
tc RBIG-deep4 gen_BIG n=100000 mode=deep rooted=1
tc RBIG-deeper1 gen_BIG n=50000 mode=deeper rooted=1
tc RBIG-deeper2 gen_BIG n=51000 mode=deeper rooted=1
tc RBIG-deeper3 gen_BIG n=99000 mode=deeper rooted=1
tc RBIG-deeper4 gen_BIG n=99000 mode=deeper rooted=1
tc RBIG-deeper5 gen_BIG n=100000 mode=deeper rooted=1
tc RBIG-deeper6 gen_BIG n=100000 mode=deeper rooted=1

group group5 12
limits n=250 rooted=0
tc 3
tc small-random1 gen_BIG n=50 mode=random rooted=0
tc small-random2 gen_BIG n=51 mode=random rooted=0
tc small-random3 gen_BIG n=99 mode=random rooted=0
tc small-random4 gen_BIG n=99 mode=random rooted=0
tc small-random5 gen_BIG n=100 mode=random rooted=0
tc small-random6 gen_BIG n=100 mode=random rooted=0
tc small-star1 gen_BIG n=51 mode=star rooted=0
tc small-star2 gen_BIG n=100 mode=star rooted=0
tc small-deep1 gen_BIG n=50 mode=deep rooted=0
tc small-deep2 gen_BIG n=99 mode=deep rooted=0
tc small-deep3 gen_BIG n=250 mode=deep rooted=0
tc small-deep4 gen_BIG n=250 mode=deep rooted=0
tc small-deeper1 gen_BIG n=250 mode=deeper rooted=0
tc small-deeper2 gen_BIG n=250 mode=deeper rooted=0
tc small-deeper3 gen_BIG n=250 mode=deeper rooted=0
tc small-deeper4 gen_BIG n=250 mode=deeper rooted=0
tc small-deeper5 gen_BIG n=250 mode=deeper rooted=0
tc small-deeper6 gen_BIG n=250 mode=deeper rooted=0

group group6 28
limits n=100000 rooted=0
include_group group2
include_group group3
include_group group4

tc BIG-random1 gen_BIG n=50000 mode=random rooted=0
tc BIG-random2 gen_BIG n=51000 mode=random rooted=0
tc BIG-random3 gen_BIG n=99000 mode=random rooted=0
tc BIG-random4 gen_BIG n=99000 mode=random rooted=0
tc BIG-random5 gen_BIG n=100000 mode=random rooted=0
tc BIG-random6 gen_BIG n=100000 mode=random rooted=0
tc BIG-star1 gen_BIG n=51000 mode=star rooted=0
tc BIG-star2 gen_BIG n=100000 mode=star rooted=0
tc BIG-deep1 gen_BIG n=50000 mode=deep rooted=0
tc BIG-deep2 gen_BIG n=99000 mode=deep rooted=0
tc BIG-deep3 gen_BIG n=100000 mode=deep rooted=0
tc BIG-deep4 gen_BIG n=100000 mode=deep rooted=0
tc BIG-deeper1 gen_BIG n=50000 mode=deeper rooted=0
tc BIG-deeper2 gen_BIG n=51000 mode=deeper rooted=0
tc BIG-deeper3 gen_BIG n=99000 mode=deeper  rooted=0
tc BIG-deeper4 gen_BIG n=99000 mode=deeper rooted=0
tc BIG-deeper5 gen_BIG n=100000 mode=deeper rooted=0
tc BIG-deeper6 gen_BIG n=100000 mode=deeper rooted=0
