#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution solution.cpp opt

MAXN=1000000000
MAXK=100000

samplegroup
limits nMax=$MAXN mMax=$MAXN kMax=$MAXK
sample 1
sample 2

group group1 24
limits nMax=1000 mMax=1000 kMax=$MAXK
tc 1
tc 2
tc_manual ../manual-tests/03.in
tc_manual ../manual-tests/04.in
tc_manual ../manual-tests/05.in
tc_manual ../manual-tests/06.in
tc_manual ../manual-tests/07.in
tc_manual ../manual-tests/08.in
tc_manual ../manual-tests/09.in
tc_manual ../manual-tests/10.in
tc_manual ../manual-tests/11.in
tc_manual ../manual-tests/12.in
tc_manual ../manual-tests/13.in
tc_manual ../manual-tests/14.in
tc_manual ../manual-tests/15.in
tc_manual ../manual-tests/16.in
tc_manual ../manual-tests/17.in
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
tc_manual ../manual-tests/31.in
tc_manual ../manual-tests/32.in
tc_manual ../manual-tests/33.in
tc_manual ../manual-tests/34.in
tc_manual ../manual-tests/35.in
tc_manual ../manual-tests/36.in
tc_manual ../manual-tests/37.in
tc_manual ../manual-tests/38.in

group group2 20
limits nMax=5 mMax=$MAXN kMax=$MAXK
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
tc_manual ../manual-tests/55.in
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

group group3 12
limits nMax=100000 mMax=100000 kMax=$MAXK
include_group group1
tc_manual ../manual-tests/69.in
tc_manual ../manual-tests/70.in
tc_manual ../manual-tests/71.in
tc_manual ../manual-tests/72.in
tc_manual ../manual-tests/73.in
tc_manual ../manual-tests/74.in
tc_manual ../manual-tests/75.in
tc_manual ../manual-tests/76.in
tc_manual ../manual-tests/77.in
tc_manual ../manual-tests/94.in
tc_manual ../manual-tests/95.in
tc_manual ../manual-tests/96.in
tc_manual ../manual-tests/97.in
tc_manual ../manual-tests/98.in
tc_manual ../manual-tests/99.in
tc_manual ../manual-tests/100.in
tc_manual ../manual-tests/101.in
tc_manual ../manual-tests/102.in
tc_manual ../manual-tests/103.in
tc_manual ../manual-tests/104.in
tc_manual ../manual-tests/105.in
tc_manual ../manual-tests/106.in
tc_manual ../manual-tests/107.in
tc_manual ../manual-tests/108.in
tc_manual ../manual-tests/109.in
tc_manual ../manual-tests/110.in
tc_manual ../manual-tests/111.in
tc_manual ../manual-tests/112.in
tc_manual ../manual-tests/113.in
tc_manual ../manual-tests/114.in
tc_manual ../manual-tests/115.in
tc_manual ../manual-tests/116.in

group group4 15
limits nMax=$MAXN mMax=$MAXN kMax=1000
tc_manual ../manual-tests/148.in
tc_manual ../manual-tests/149.in
tc_manual ../manual-tests/150.in
tc_manual ../manual-tests/151.in
tc_manual ../manual-tests/152.in
tc_manual ../manual-tests/153.in
tc_manual ../manual-tests/154.in
tc_manual ../manual-tests/155.in
tc_manual ../manual-tests/156.in
tc_manual ../manual-tests/157.in
tc_manual ../manual-tests/158.in
tc_manual ../manual-tests/159.in
tc_manual ../manual-tests/160.in
tc_manual ../manual-tests/161.in
tc_manual ../manual-tests/162.in
tc_manual ../manual-tests/163.in
tc_manual ../manual-tests/164.in
tc_manual ../manual-tests/165.in
tc_manual ../manual-tests/166.in
tc_manual ../manual-tests/167.in
tc_manual ../manual-tests/168.in
tc_manual ../manual-tests/169.in
tc_manual ../manual-tests/170.in
tc_manual ../manual-tests/171.in

group group5 29
limits nMax=$MAXN mMax=$MAXN kMax=$MAXK
include_group group2
include_group group3
include_group group4
tc_manual ../manual-tests/117.in
tc_manual ../manual-tests/118.in
tc_manual ../manual-tests/119.in
tc_manual ../manual-tests/120.in
tc_manual ../manual-tests/121.in
tc_manual ../manual-tests/122.in
tc_manual ../manual-tests/123.in
tc_manual ../manual-tests/124.in
tc_manual ../manual-tests/125.in
tc_manual ../manual-tests/126.in
tc_manual ../manual-tests/127.in
tc_manual ../manual-tests/128.in
tc_manual ../manual-tests/129.in
tc_manual ../manual-tests/130.in
tc_manual ../manual-tests/131.in
tc_manual ../manual-tests/132.in
tc_manual ../manual-tests/133.in
tc_manual ../manual-tests/134.in
tc_manual ../manual-tests/135.in
tc_manual ../manual-tests/136.in
tc_manual ../manual-tests/137.in
tc_manual ../manual-tests/138.in
tc_manual ../manual-tests/139.in
tc_manual ../manual-tests/140.in
tc_manual ../manual-tests/141.in
tc_manual ../manual-tests/142.in
tc_manual ../manual-tests/143.in
tc_manual ../manual-tests/144.in
tc_manual ../manual-tests/145.in
tc_manual ../manual-tests/146.in
tc_manual ../manual-tests/147.in

tc_manual ../manual-tests/172.in
tc_manual ../manual-tests/173.in
tc_manual ../manual-tests/174.in
tc_manual ../manual-tests/175.in
tc_manual ../manual-tests/176.in
tc_manual ../manual-tests/177.in
tc_manual ../manual-tests/178.in
tc_manual ../manual-tests/179.in
tc_manual ../manual-tests/180.in
tc_manual ../manual-tests/181.in
tc_manual ../manual-tests/182.in
tc_manual ../manual-tests/183.in

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
tc_manual ../manual-tests/90.in
tc_manual ../manual-tests/91.in
tc_manual ../manual-tests/92.in
tc_manual ../manual-tests/93.in
