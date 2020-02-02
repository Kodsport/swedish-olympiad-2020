#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution sl.cpp

#Compile python-files for sample generating
compile gen_random.py
compile gen_break_solution.py
compile gen_break_naive.py
compile gen_break_soll.py

MAXN=200000
MAXQ=200000

samplegroup
limits nMax=$MAXN qMax=$MAXQ
sample 1
sample 2
sample 3
sample 4


group group1 25
limits nMax=$MAXN qMax=$MAXQ fewUnlock=1
#tc name input_generator inputs_to_generator
tc 1
tc 2
tc 3
tc 4
tc small0_g1 gen_random N=10 Q=10 different_Bs=0 q1=4 q2=4 q3=2 randMethod=plain  
tc small1_g1 gen_random N=10 Q=10 different_Bs=0 q1=3 q2=5 q3=2 randMethod=plain  
tc small2_g1 gen_random N=10 Q=10 different_Bs=0 q1=2 q2=4 q3=4 randMethod=plain  
tc large0plain_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=149980 q3=50000 randMethod=plain  
tc large1plain_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=139980 q3=60000 randMethod=plain  
tc large2plain_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=159980 q3=40000 randMethod=plain  
tc large0_half_below_sqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=139980 q3=60000 randMethod=_half_below_sqrtN  
tc large1_half_below_sqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=149980 q3=50000 randMethod=_half_below_sqrtN  
tc large2_half_below_sqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=159980 q3=40000 randMethod=_half_below_sqrtN  
tc large0_95percent_below_sqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=139980 q3=60000 randMethod=_95percent_below_sqrtN  
tc large1_95percent_below_sqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=149980 q3=50000 randMethod=_95percent_below_sqrtN  
tc large2_95percent_below_sqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=159980 q3=40000 randMethod=_95percent_below_sqrtN  
tc large0_95percent_below_sqrtsqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=139980 q3=60000 randMethod=_95percent_below_sqrtsqrtN  
tc large1_95percent_below_sqrtsqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=149980 q3=50000 randMethod=_95percent_below_sqrtsqrtN  
tc large2_95percent_below_sqrtsqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=159980 q3=40000 randMethod=_95percent_below_sqrtsqrtN  
tc large0_95percent_below_smallersqrtsqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=139980 q3=60000 randMethod=_95percent_below_smallersqrtsqrtN  
tc large1_95percent_below_smallersqrtsqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=149980 q3=50000 randMethod=_95percent_below_smallersqrtsqrtN  
tc large2_95percent_below_smallersqrtsqrtN_g1 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20 q2=159980 q3=40000 randMethod=_95percent_below_smallersqrtsqrtN  
tc breakN gen_break_solution N=$MAXN toBreak=$MAXN
tc break1 gen_break_solution N=$MAXN toBreak=1
tc break_soll0_g1 gen_break_soll
tc break_soll1_g1 gen_break_soll


group group2 30
limits nMax=$MAXN qMax=$MAXQ noDelDiffB=1
#tc name input_generator inputs_to_generator
tc small0_g2 gen_random N=10 Q=10 different_Bs=1 q1=6 q2=4 q3=0 randMethod=plain  
tc small1_g2 gen_random N=10 Q=10 different_Bs=1 q1=5 q2=5 q3=0 randMethod=plain  
tc small2_g2 gen_random N=10 Q=10 different_Bs=1 q1=4 q2=6 q3=0 randMethod=plain  
tc large0_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=100000 q2=100000 q3=0
tc large1_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=90000 q2=110000 q3=0
tc large2_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=80000 q2=120000 q3=0
tc large3_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=70000 q2=130000 q3=0
tc large4_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=60000 q2=140000 q3=0
tc large5_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=50000 q2=150000 q3=0
tc large6_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=40000 q2=160000 q3=0  
tc large7_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=30000 q2=170000 q3=0  
tc large8_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=20000 q2=180000 q3=0  
tc large0_largest_possible_g2 gen_random N=$MAXN Q=$MAXQ different_Bs=1 q1=40000 q2=160000 q3=0 randMethod=_only_largest  
tc breakN
tc break1
tc break_naive0_g2 gen_break_naive  
tc break_naive1_g2 gen_break_naive shuffle=1


group group3 45
limits nMax=$MAXN qMax=$MAXQ
#tc name input_generator inputs_to_generator
include_group group1
include_group group2
tc small0_g3 gen_random N=10 Q=10 different_Bs=0 q1=4 q2=4 q3=2 randMethod=plain 
tc small1_g3 gen_random N=10 Q=10 different_Bs=0 q1=6 q2=3 q3=1 randMethod=plain 
tc small2_g3 gen_random N=10 Q=10 different_Bs=0 q1=5 q2=4 q3=1 randMethod=plain 
tc large0plain_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20000 q2=150000 q3=30000 randMethod=plain  
tc large1plain_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=30000 q2=150000 q3=20000 randMethod=plain  
tc large2plain_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=40000 q2=140000 q3=20000 randMethod=plain  
tc large0_half_below_sqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20000 q2=150000 q3=30000 randMethod=_half_below_sqrtN  
tc large1_half_below_sqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=30000 q2=150000 q3=20000 randMethod=_half_below_sqrtN  
tc large2_half_below_sqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=40000 q2=140000 q3=20000 randMethod=_half_below_sqrtN  
tc large0_95percent_below_sqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20000 q2=150000 q3=30000 randMethod=_95percent_below_sqrtN  
tc large1_95percent_below_sqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=30000 q2=150000 q3=20000 randMethod=_95percent_below_sqrtN  
tc large2_95percent_below_sqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=40000 q2=140000 q3=20000 randMethod=_95percent_below_sqrtN  
tc large0_95percent_below_sqrtsqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20000 q2=150000 q3=30000 randMethod=_95percent_below_sqrtsqrtN  
tc large1_95percent_below_sqrtsqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=30000 q2=150000 q3=20000 randMethod=_95percent_below_sqrtsqrtN  
tc large2_95percent_below_sqrtsqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=40000 q2=140000 q3=20000 randMethod=_95percent_below_sqrtsqrtN  
tc large0_95percent_above_NsqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=20000 q2=100000 q3=80000 randMethod=_95percent_above_NsqrtN  
tc large1_95percent_above_NsqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=30000 q2=100000 q3=70000 randMethod=_95percent_above_NsqrtN  
tc large2_95percent_above_NsqrtN_g3 gen_random N=$MAXN Q=$MAXQ different_Bs=0 q1=40000 q2=100000 q3=60000 randMethod=_95percent_above_NsqrtN  
