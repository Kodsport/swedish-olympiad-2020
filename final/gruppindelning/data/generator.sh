#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution eae.cpp

compile Gruppindelning_generator.py
compile gen_longcycles.py
ulimit -s unlimited

samplegroup
limits n=10
sample 1
sample 2
sample 3

group group1 12
limits n=16
tc 2
tc 3
tc small11 Gruppindelning_generator n=10 m=1 arg=random
tc small12 Gruppindelning_generator n=10 m=1 arg=random
tc small13 Gruppindelning_generator n=10 m=1 arg=solvable
tc small14 Gruppindelning_generator n=11 m=5 arg=random
tc small15 Gruppindelning_generator n=11 m=5 arg=random
tc small16 Gruppindelning_generator n=11 m=5 arg=solvable
tc small17 Gruppindelning_generator n=15 m=2 arg=random
tc small18 Gruppindelning_generator n=15 m=2 arg=random
tc small19 Gruppindelning_generator n=15 m=2 arg=solvable
tc small110 Gruppindelning_generator n=15 m=5 arg=random
tc small111 Gruppindelning_generator n=15 m=5 arg=random
tc small112 Gruppindelning_generator n=15 m=5 arg=solvable
tc small113 Gruppindelning_generator n=15 m=7 arg=random
tc small114 Gruppindelning_generator n=15 m=7 arg=random
tc small115 Gruppindelning_generator n=15 m=7 arg=solvable
tc small116 Gruppindelning_generator n=15 m=0 arg=random
tc small117 gen_longcycles n=15 m=6
tc small118 gen_longcycles n=15 m=6
tc small119 gen_longcycles n=15 m=5
tc small120 gen_longcycles n=15 m=5

group group2 23
limits n=40
include_group group1
tc small21 Gruppindelning_generator n=39 m=15 arg=random
tc small22 Gruppindelning_generator n=39 m=15 arg=random
tc small23 Gruppindelning_generator n=39 m=15 arg=solvable
tc small24 Gruppindelning_generator n=39 m=19 arg=random
tc small25 Gruppindelning_generator n=39 m=19 arg=random
tc small26 Gruppindelning_generator n=39 m=19 arg=solvable
tc small27 Gruppindelning_generator n=40 m=15 arg=random
tc small28 Gruppindelning_generator n=40 m=15 arg=random
tc small29 Gruppindelning_generator n=40 m=15 arg=solvable
tc small210 Gruppindelning_generator n=40 m=19 arg=random
tc small211 Gruppindelning_generator n=40 m=19 arg=random
tc small212 Gruppindelning_generator n=40 m=19 arg=solvable
tc small213 Gruppindelning_generator n=40 m=0 arg=random
tc small214 gen_longcycles n=40 m=18
tc small215 gen_longcycles n=40 m=17
tc small216 gen_longcycles n=40 m=16
tc small217 gen_longcycles n=40 m=15
tc small218 gen_longcycles n=40 m=17 arg=several
tc small219 gen_longcycles n=40 m=18 arg=several



group group3 25
limits n=100000 consecutive=1
tc 1
tc line1 Gruppindelning_generator n=99999 m=10000 arg=line
tc line2 Gruppindelning_generator n=99999 m=10000 arg=line_inp
tc line3 Gruppindelning_generator n=99999 m=10001 arg=line
tc line4 Gruppindelning_generator n=99999 m=10001 arg=line
tc line5 Gruppindelning_generator n=99999 m=40000 arg=line
tc line6 Gruppindelning_generator n=99999 m=40000 arg=line_inp
tc line7 Gruppindelning_generator n=99999 m=40001 arg=line
tc line8 Gruppindelning_generator n=99999 m=40001 arg=line
tc line9 Gruppindelning_generator n=100000 m=10000 arg=line
tc line10 Gruppindelning_generator n=100000 m=10000 arg=line_inp
tc line11 Gruppindelning_generator n=100000 m=10001 arg=line
tc line12 Gruppindelning_generator n=100000 m=10001 arg=line
tc line13 Gruppindelning_generator n=100000 m=49999 arg=line
tc line14 Gruppindelning_generator n=100000 m=49999 arg=line_inp
tc line15 Gruppindelning_generator n=100000 m=49999 arg=line
tc line16 Gruppindelning_generator n=100000 m=49999 arg=line
tc line17 Gruppindelning_generator n=100000 m=0 arg=line

group group4 40
limits n=100000
include_group group2
include_group group3
tc BIG11 Gruppindelning_generator n=99999 m=10000 arg=random
tc BIG12 Gruppindelning_generator n=99999 m=10000 arg=random
tc BIG13 Gruppindelning_generator n=99999 m=10000 arg=solvable
tc BIG14 Gruppindelning_generator n=99999 m=40000 arg=random
tc BIG15 Gruppindelning_generator n=99999 m=40000 arg=random
tc BIG16 Gruppindelning_generator n=99999 m=40000 arg=solvable
tc BIG17 Gruppindelning_generator n=100000 m=10000 arg=random
tc BIG18 Gruppindelning_generator n=100000 m=10000 arg=random
tc BIG19 Gruppindelning_generator n=100000 m=10000 arg=solvable
tc BIG110 Gruppindelning_generator n=100000 m=49999 arg=random
tc BIG111 Gruppindelning_generator n=100000 m=49999 arg=random
tc BIG112 Gruppindelning_generator n=100000 m=49999 arg=solvable
tc BIG113 Gruppindelning_generator n=100000 m=0 arg=random
tc BIG114 gen_longcycles n=100000 m=49996
tc BIG115 gen_longcycles n=100000 m=49994
tc BIG116 gen_longcycles n=100000 m=49995
tc BIG117 gen_longcycles n=100000 m=49993
tc BIG118 gen_longcycles n=100000 m=49996 arg=several
tc BIG119 gen_longcycles n=100000 m=49995 arg=several
tc BIG120 gen_longcycles n=100000 m=49996 arg=solvable
tc BIG121 gen_longcycles n=100000 m=49994 arg=solvable
