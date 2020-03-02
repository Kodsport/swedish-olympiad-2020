#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution solution.cpp opt

MAXN=1000000
MAXQ=300000

samplegroup
limits nMax=$MAXN mMax=$MAXN qMax=$MAXQ
sample 1

group group1 21
limits nMax=1 mMax=$MAXN qMax=$MAXQ
tc_manual ../manual-tests/02.in
tc_manual ../manual-tests/07.in
tc_manual ../manual-tests/17.in
tc_manual ../manual-tests/34.in
tc_manual ../manual-tests/55.in
tc_manual ../manual-tests/77.in
tc_manual ../manual-tests/90.in

group group2 14
limits nMax=50 mMax=50 qMax=4000
tc 1
#tc_manual ../manual-tests/02.in
tc_manual ../manual-tests/03.in
tc_manual ../manual-tests/04.in
tc_manual ../manual-tests/05.in
tc_manual ../manual-tests/06.in
#tc_manual ../manual-tests/07.in
tc_manual ../manual-tests/08.in
tc_manual ../manual-tests/09.in
tc_manual ../manual-tests/10.in
tc_manual ../manual-tests/11.in
tc_manual ../manual-tests/12.in
tc_manual ../manual-tests/13.in

group group3 28
limits nMax=10000 mMax=10000 qMax=10000
include_group group2
tc_manual ../manual-tests/14.in
tc_manual ../manual-tests/15.in
tc_manual ../manual-tests/16.in
#tc_manual ../manual-tests/17.in
tc_manual ../manual-tests/18.in
tc_manual ../manual-tests/19.in
tc_manual ../manual-tests/20.in
tc_manual ../manual-tests/21.in
tc_manual ../manual-tests/22.in
tc_manual ../manual-tests/23.in
tc_manual ../manual-tests/24.in
tc_manual ../manual-tests/25.in
tc_manual ../manual-tests/26.in
tc_manual ../manual-tests/27.in
tc_manual ../manual-tests/28.in
tc_manual ../manual-tests/29.in
tc_manual ../manual-tests/30.in

group group4 37
limits nMax=$MAXN mMax=$MAXN qMax=$MAXQ
include_group group1
include_group group3
tc_manual ../manual-tests/31.in
tc_manual ../manual-tests/32.in
tc_manual ../manual-tests/33.in
#tc_manual ../manual-tests/34.in
tc_manual ../manual-tests/35.in
tc_manual ../manual-tests/36.in
tc_manual ../manual-tests/37.in
tc_manual ../manual-tests/38.in
tc_manual ../manual-tests/39.in
tc_manual ../manual-tests/40.in
tc_manual ../manual-tests/41.in
tc_manual ../manual-tests/42.in
tc_manual ../manual-tests/43.in
tc_manual ../manual-tests/44.in
tc_manual ../manual-tests/45.in
tc_manual ../manual-tests/46.in
tc_manual ../manual-tests/47.in
tc_manual ../manual-tests/48.in
tc_manual ../manual-tests/49.in
tc_manual ../manual-tests/50.in
tc_manual ../manual-tests/51.in
tc_manual ../manual-tests/52.in
tc_manual ../manual-tests/53.in
tc_manual ../manual-tests/54.in
#tc_manual ../manual-tests/55.in
tc_manual ../manual-tests/56.in
tc_manual ../manual-tests/57.in
tc_manual ../manual-tests/58.in
tc_manual ../manual-tests/59.in
tc_manual ../manual-tests/60.in
tc_manual ../manual-tests/61.in
tc_manual ../manual-tests/62.in
tc_manual ../manual-tests/63.in
tc_manual ../manual-tests/64.in
tc_manual ../manual-tests/65.in
tc_manual ../manual-tests/66.in
tc_manual ../manual-tests/67.in
tc_manual ../manual-tests/68.in
tc_manual ../manual-tests/69.in
tc_manual ../manual-tests/70.in
tc_manual ../manual-tests/71.in
tc_manual ../manual-tests/72.in
tc_manual ../manual-tests/73.in
tc_manual ../manual-tests/74.in
tc_manual ../manual-tests/75.in
tc_manual ../manual-tests/76.in
#tc_manual ../manual-tests/77.in
tc_manual ../manual-tests/78.in
tc_manual ../manual-tests/79.in
tc_manual ../manual-tests/80.in
tc_manual ../manual-tests/81.in
tc_manual ../manual-tests/82.in
tc_manual ../manual-tests/83.in
tc_manual ../manual-tests/84.in
tc_manual ../manual-tests/85.in
tc_manual ../manual-tests/86.in
tc_manual ../manual-tests/87.in
tc_manual ../manual-tests/88.in
tc_manual ../manual-tests/89.in
#tc_manual ../manual-tests/90.in
tc_manual ../manual-tests/91.in
tc_manual ../manual-tests/92.in
tc_manual ../manual-tests/93.in
tc_manual ../manual-tests/94.in
tc_manual ../manual-tests/95.in
tc_manual ../manual-tests/96.in
tc_manual ../manual-tests/97.in
tc_manual ../manual-tests/98.in
tc_manual ../manual-tests/99.in


