#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution jb.cpp

#Compile python-files for sample generating
compile gen_random.py
compile gen_maxcase.py
compile gen_stairs.py

MAXN=200000
MAXQ=200000
MAXW=1000000000
MAXH=1000000000

samplegroup
limits nMax=$MAXN qMax=$MAXQ hMax=$MAXH wMax=$MAXW sMax=$MAXN
sample 1
sample 2


group group1 15
limits nMax=100 qMax=100 hMax=500 wMax=500 sMax=100
tc 1
tc 2
tc small0_g1 gen_random N=8 Q=10
tc small1_g1 gen_random N=10 Q=8
tc small2_g1 gen_random N=10 Q=10
tc medium0_g1 gen_random N=100 Q=100 H=10 W=500
tc medium1_g1 gen_random N=100 Q=100 H=500 W=500
tc medium2_g1 gen_random N=99  Q=99  H=499 W=499
tc medium3_g1 gen_random N=9  Q=99  H=499 W=499
tc medium4_g1 gen_random N=1  Q=100 H=500 W=500
tc nostalagmite_g1 gen_random N=100 Q=99 H=500 W=500 N1=0
tc nostalactite_g1 gen_random N=99 Q=100 H=500 W=500 N2=0
tc fewstalagmite0_g1 gen_random N=100 Q=100 H=500 W=500 N1=2
tc fewstalagmite1_g1 gen_random N=100 Q=100 H=500 W=500 N1=12
tc fewstalagmite2_g1 gen_random N=10 Q=100 H=500 W=500 N1=1
tc fewstalactite0_g1 gen_random N=100 Q=100 H=500 W=500 N2=2
tc fewstalactite1_g1 gen_random N=100 Q=100 H=500 W=500 N2=12
tc fewstalactite2_g1 gen_random N=10 Q=100 H=500 W=500 N2=1
tc maxcase0_g1 gen_maxcase N=100 Q=100 H=500 W=500 top=1 bot=1 space=2
tc maxcase1_g1 gen_maxcase N=100 Q=60 H=500 W=500 top=10 bot=10 space=4
tc maxcase2_g1 gen_maxcase N=10 Q=60 H=500 W=500 top=10 bot=10 space=4
tc stairs0_g1 gen_stairs N=100 Q=100 H=500 gap=1 prob1=0.3
tc stairs1_g1 gen_stairs N=100 Q=100 H=500 gap=-5 prob1=0.9 reverse=1
tc stairs2_g1 gen_stairs N=100 Q=100 H=500 gap=2 prob1=0.6 same_direction=1


group group2 20
limits nMax=2000 qMax=2000 hMax=2000000 wMax=2000000 sMax=2000
include_group group1
tc large0_g2 gen_random N=2000 Q=2000 H=2000000 W=20000
tc large1_g2 gen_random N=2000 Q=2000 H=20000 W=2000000
tc large2_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000
tc large3_g2 gen_random N=200 Q=2000 H=2000000 W=2000000
tc large4_g2 gen_random N=20 Q=2000 H=2000000 W=2000000
tc nostalagmite_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000 N1=0
tc nostalactite_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000 N2=0
tc fewstalagmite0_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000 N1=15
tc fewstalagmite1_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000 N1=123
tc fewstalagmite2_g2 gen_random N=200 Q=2000 H=2000000 W=2000000 N1=12
tc fewstalactite0_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000 N2=15
tc fewstalactite1_g2 gen_random N=2000 Q=2000 H=2000000 W=2000000 N2=123
tc fewstalactite2_g2 gen_random N=200 Q=2000 H=2000000 W=2000000 N2=12
tc maxcase1_g2 gen_maxcase N=2000 Q=2000 H=2000000 W=2000000 top=1 bot=1 space=2
tc maxcase2_g2 gen_maxcase N=2000 Q=2000 H=2000000 W=2000000 top=2000 bot=103 space=3
tc maxcase3_g2 gen_maxcase N=2000 Q=2000 H=2000000 W=2000000 top=900 bot=99999 space=101
tc maxcase4_g2 gen_maxcase N=200 Q=2000 H=2000000 W=2000000 top=1500000 bot=1500000 space=2
tc maxcase5_g2 gen_maxcase N=20 Q=2000 H=2000000 W=2000000 top=1500000 bot=1500000 space=2
tc stairs0_g2 gen_stairs N=2000 Q=2000 H=2000000 gap=1 prob1=0.8
tc stairs1_g2 gen_stairs N=2000 Q=2000 H=2000000 gap=-50 prob1=0.1 reverse=1 same_direction=1
tc stairs2_g2 gen_stairs N=2000 Q=2000 H=2000000 gap=-2 prob1=0.5 same_direction=1

group group3 25
limits nMax=$MAXN qMax=$MAXQ hMax=$MAXH wMax=$MAXW sMax=15
tc small0_g1
tc small1_g1
tc small2_g1
tc nostalactite_g1
tc fewstalactite0_g1
tc fewstalactite1_g1
tc fewstalactite2_g1
tc nostalactite_g2
tc fewstalactite0_g2
tc nostalactite0_g3 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=0
tc nostalactite1_g3 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=0
tc fewstalactite0_g3 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=14
tc fewstalactite1_g3 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=14
tc fewstalactite2_g3 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=15
tc fewstalactite3_g3 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=15
tc fewstalactite4_g3 gen_random N=200 Q=$MAXQ H=$MAXH W=$MAXW N2=15
tc fewstalactite5_g3 gen_random N=20 Q=$MAXQ H=$MAXH W=$MAXW N2=15
tc stairs0_g3 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=1 prob1=1
tc stairs1_g3 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=1 prob1=1 reverse=1


group group4 40
limits nMax=$MAXN qMax=$MAXQ hMax=$MAXH wMax=$MAXW sMax=$MAXN
include_group group1
include_group group2
include_group group3
tc large0_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW
tc large1_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW
tc large2_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW
tc large3_g4 gen_random N=20000 Q=$MAXQ H=$MAXH W=$MAXW
tc large4_g4 gen_random N=2000 Q=$MAXQ H=$MAXH W=$MAXW
tc large5_g4 gen_random N=200 Q=$MAXQ H=$MAXH W=$MAXW
tc large6_g4 gen_random N=20 Q=$MAXQ H=$MAXH W=$MAXW
tc large7_g4 gen_random N=2 Q=$MAXQ H=$MAXH W=$MAXW
tc nostalagmite_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N1=0
tc nostalactite_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=0
tc fewstalagmite0_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N1=200
tc fewstalagmite1_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N1=12345
tc fewstalactite0_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=200
tc fewstalactite1_g4 gen_random N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW N2=12345
tc maxcase0_g4 gen_maxcase N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW top=1 bot=1 space=2
tc maxcase1_g4 gen_maxcase N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW top=2 bot=2 space=321
tc maxcase2_g4 gen_maxcase N=$MAXN Q=$MAXQ H=$MAXH W=$MAXW top=1232 bot=31232 space=500
tc maxcase3_g4 gen_maxcase N=20000 Q=$MAXQ H=$MAXH W=$MAXW top=2 bot=2 space=321
tc maxcase4_g4 gen_maxcase N=2000 Q=$MAXQ H=$MAXH W=$MAXW top=2 bot=2 space=32
tc maxcase5_g4 gen_maxcase N=200 Q=$MAXQ H=$MAXH W=$MAXW top=$MAXH bot=$MAXH space=2212
tc maxcase6_g4 gen_maxcase N=20 Q=$MAXQ H=$MAXH W=$MAXW top=232342 bot=2234234 space=2213
tc maxcase7_g4 gen_maxcase N=2 Q=$MAXQ H=$MAXH W=$MAXW top=2122323 bot=222343 space=2210
tc stairs0_g4 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=1 prob1=0.01
tc stairs1_g4 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=12 prob1=0.01 same_direction=1
tc stairs2_g4 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=1 prob1=0.5
tc stairs3_g4 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=-1 prob1=0.5 reverse=1
tc stairs4_g4 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=-123456 prob1=0.5 reverse=1 same_direction=1
tc stairs5_g4 gen_stairs N=$MAXN Q=$MAXQ H=$MAXH gap=123456 prob1=0.5 same_direction=1


