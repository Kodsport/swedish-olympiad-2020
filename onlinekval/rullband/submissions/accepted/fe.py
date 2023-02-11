#!/usr/bin/python
from heapq import *

def solve(n,m,g,band):
    e = [[] for _ in range(m)]
    for b in band:
        e[b[0]].append([b[1],b[2]])
    
    seen = [False]*m
    q = []
    heappush(q, (0,0))
    while len(q):
        dist,v = heappop(q)
        if v<0 or v>=m or seen[v]:
            continue
        if v==m-1:
            return dist+g
        seen[v] = True
        heappush(q,(dist+g,v-1))
        heappush(q,(dist+g,v+1))
        for u,d in e[v]:
            heappush(q,(dist+d,u))
    assert(False)

n,m,g = map(int,input().split())

band = []
for _ in range(n):
    a,b,t = map(int,input().split())
    band.append([a-1,b-1,t])


print(solve(n,m,g,band))
