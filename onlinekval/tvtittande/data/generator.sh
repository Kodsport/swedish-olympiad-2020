#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen_random.py
compile gen_smart.py

MAX=200000

samplegroup
limits nMax=10 kMax=10
sample 1
sample 2
sample 3

group group1 40
limits nMax=50 kMax=50
tc 1
tc 2
tc 3
tc small-rand-1 gen_random n=1 k=1 days=1 maxlength=10 csum=1
tc small-rand-2 gen_random n=1 k=1 days=1 maxlength=100000 csum=1
tc small-rand-3 gen_random n=1 k=1 days=100000 maxlength=100000 csum=1
tc small-rand-4 gen_random n=2 k=1 days=10000 maxlength=100000 csum=2
tc small-rand-5 gen_random n=2 k=2 days=10000 maxlength=100000 csum=4
tc small-rand-6 gen_random n=10 k=1 days=100000 maxlength=100000 csum=10
tc small-rand-7 gen_random n=10 k=2 days=100000 maxlength=100000 csum=10
tc small-rand-8 gen_random n=10 k=4 days=100000 maxlength=50000 csum=20
tc small-rand-9 gen_random n=50 k=4 days=1000 maxlength=5000 csum=200
tc small-rand-10 gen_random n=50 k=50 days=100000 maxlength=10000 csum=2500

tc small-smart-1 gen_smart n=49 k=49 days=500 ans=Ja maxcsum=310
tc small-smart-2 gen_smart n=49 k=49 days=500 ans=Nej
tc small-smart-3 gen_smart n=50 k=50 days=99998 ans=Nej maxcsum=60
tc small-smart-4 gen_smart n=50 k=10 days=100000 ans=Ja maxcsum=200
tc small-smart-5 gen_smart n=50 k=10 days=100000 ans=Nej maxcsum=200
tc small-smart-6 gen_smart n=10 k=50 days=100000 ans=Ja
tc small-smart-7 gen_smart n=10 k=50 days=100000 ans=Nej maxcsum=100
tc small-smart-8 gen_smart n=50 k=50 days=100000 ans=Ja
tc small-smart-9 gen_smart n=50 k=50 days=100000 ans=Nej
tc small-smart-10 gen_smart n=50 k=10 days=100 ans=Nej
tc small-smart-11 gen_smart n=50 k=10 days=50 ans=Ja maxcsum=200
tc small-smart-12 gen_smart n=50 k=10 days=50 ans=Nej
tc small-smart-13 gen_smart n=50 k=15 days=53 ans=Ja
tc small-smart-14 gen_smart n=50 k=15 days=53 ans=Nej
tc small-smart-15 gen_smart n=10 k=50 days=1000 ans=Ja
tc small-smart-16 gen_smart n=50 k=50 days=100000 ans=Nej f=0
tc small-smart-17 gen_smart n=50 k=50 days=100000 ans=Ja f=0.5
tc small-smart-18 gen_smart n=50 k=50 days=100000 ans=Ja f=0.03
tc small-smart-19 gen_smart n=20 k=50 days=100000 ans=Ja concentrated=1
tc small-smart-20 gen_smart n=20 k=50 days=200000 ans=Nej concentrated=1
tc small-smart-21 gen_smart n=50 k=1 days=100000 ans=Ja

group group2 20
limits nMax=3000 kMax=3000
include_group group1
tc med-rand-1 gen_random n=500 k=50 days=600 maxlength=14 csum=20000
tc med-rand-2 gen_random n=100 k=500 days=600 maxlength=5 csum=3000
tc med-rand-3 gen_random n=3000 k=5 days=100000 maxlength=110000 csum=3200
tc med-rand-4 gen_random n=3000 k=5 days=100000 maxlength=100000 csum=12000
tc med-rand-5 gen_random n=10 k=3000 days=100000 maxlength=800 csum=3200
tc med-rand-6 gen_random n=10 k=3000 days=100000 maxlength=700 csum=18000
tc med-rand-7 gen_random n=3000 k=3000 days=100000 maxlength=800 csum=3200
tc med-rand-8 gen_random n=1000 k=1000 days=100000 maxlength=700 csum=100000

tc med-smart-1 gen_smart n=1 k=3000 days=85617 ans=Nej
tc med-smart-2 gen_smart n=1 k=3000 days=85617 ans=Ja
tc med-smart-3 gen_smart n=2 k=3000 days=85617 ans=Nej
tc med-smart-4 gen_smart n=2 k=3000 days=85617 ans=Ja
tc med-smart-5 gen_smart n=3000 k=2 days=100000 ans=Ja
tc med-smart-6 gen_smart n=3000 k=2 days=100000 ans=Nej
tc med-smart-7 gen_smart n=3000 k=3000 days=100000 ans=Nej
tc med-smart-8 gen_smart n=3000 k=3000 days=100000 ans=Ja
tc med-smart-9 gen_smart n=3000 k=3000 days=100000 ans=Ja f=0.5
tc med-smart-10 gen_smart n=3000 k=3000 days=100000 ans=Ja f=0.01
tc med-smart-11 gen_smart n=3000 k=3000 days=100000 ans=Nej f=0.01
tc med-smart-12 gen_smart n=3000 k=3000 days=100000 ans=Ja f=0
tc med-smart-13 gen_smart n=3000 k=3000 days=100000 ans=Nej f=0.001
tc med-smart-14 gen_smart n=50 k=3000 days=200000 ans=Ja concentrated=1
tc med-smart-15 gen_smart n=200 k=3000 days=200000 ans=Ja f=0.003
tc med-smart-16 gen_smart n=3000 k=3000 days=100000 ans=Ja f=0.01 concentrated=1
tc med-smart-17 gen_smart n=3000 k=3000 days=100000 ans=Nej f=0.01 concentrated=1
tc med-smart-18 gen_smart n=3000 k=100 days=100000 ans=Ja f=0.003
tc med-smart-19 gen_smart n=3000 k=100 days=200000 ans=Nej f=0.01

group group3 40
limits nMax=200000 kMax=200000
include_group group2
tc big-smart-1 gen_smart n=3 k=$MAX days=$MAX ans=Ja f=1
tc big-smart-2 gen_smart n=3 k=$MAX days=$MAX ans=Nej f=1
tc big-smart-3 gen_smart n=20 k=$MAX days=$MAX ans=Ja f=0.2
tc big-smart-4 gen_smart n=20 k=$MAX days=$MAX ans=Nej f=0.2
tc big-smart-5 gen_smart n=$MAX k=3 days=$MAX ans=Nej
tc big-smart-6 gen_smart n=$MAX k=3 days=$MAX ans=Ja
tc big-smart-7 gen_smart n=10000 k=$MAX days=$MAX ans=Nej
tc big-smart-8 gen_smart n=10000 k=$MAX days=$MAX ans=Ja
tc big-smart-9 gen_smart n=50000 k=$MAX days=$MAX ans=Ja
tc big-smart-10 gen_smart n=$((MAX-40000)) k=$MAX days=$MAX ans=Ja f=0.01
tc big-smart-11 gen_smart n=$((MAX-40000)) k=$MAX days=$MAX ans=Nej f=0.01
tc big-smart-12 gen_smart n=$((MAX-20000)) k=$MAX days=$MAX ans=Ja
tc big-smart-13 gen_smart n=$((MAX-2000)) k=10000 days=$MAX ans=Ja
tc big-smart-14 gen_smart n=$((MAX-2000)) k=1000 days=$MAX ans=Ja
tc big-smart-15 gen_smart n=$((MAX-2000)) k=1000 days=$MAX ans=Ja concentrated=1
tc big-smart-16 gen_smart n=$((MAX-2000)) k=1000 days=$MAX ans=Ja f=0.001 concentrated=1
tc big-smart-17 gen_smart n=$((MAX-2000)) k=10000 days=$MAX ans=Ja concentrated=1
