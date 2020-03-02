#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

#use_solution bmswapping.py python2 # ../jury_sol.cpp
use_solution ng_better.cpp

compile gen_random.py
compile gen_stars.py
compile gen_treegraph.py
compile gen_groups.py

samplegroup
limits t=0
sample_manual 1

testcase() {
	NAME=$(printf "%02d" $1)
	group group$NAME 10
	limits t=$1
	tc "case$NAME" "${@:2}" tc=$1
}

testcase 1 gen_random n=10 m=100
testcase 2 gen_random n=100 m=500
testcase 3 gen_random n=100 m=8000
testcase 4 gen_groups n=8000 m=0 k=5 #Small groups
testcase 5 gen_stars n=2500 m=8000 k=2000 #Small stars
testcase 6 gen_stars n=2500 m=9800 k=200 #Big stars
testcase 7 gen_treegraph n=2500 m=9999 #Small tree
testcase 8 gen_treegraph n=25000 m=99999 #Big tree
testcase 9 gen_random n=10000 m=100000
testcase 10 gen_random n=25000 m=100000

# Clamp final scores to 100
echo 'grading: custom' >> testdata.yaml
echo 'grading: default' >> secret/testdata.yaml
echo 'grading: default' >> sample/testdata.yaml
