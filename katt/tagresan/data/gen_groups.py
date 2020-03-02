#!/usr/bin/env python3

from common import *
#This creates a testcase with many groups where everyone knows everyone
#and where the groups are disconnected from each other.
#Define variable k which is the maximum size of the groups.
k = int(cmdlinearg('k'))
#Don't care about variable m, we will calculate that later.
edges = []
used = 0
while used<4*n:
    sz = random.randrange(0,k)+1
    sz = min(sz, 4*n-used)
    for a in range(used+1,used+sz):
        for b in range(a+1, used+1+sz):
            edges.append((a,b))
    used+=sz
print(n, len(edges))
#Remap so that identity solution doesnt get large score.
remapindex=[i for i in range(4*n)]
random.shuffle(remapindex)
remap={}
for i in range(4*n):
    remap[i+1]=remapindex[i]+1
for a,b in edges:
    print(remap[a],remap[b])
