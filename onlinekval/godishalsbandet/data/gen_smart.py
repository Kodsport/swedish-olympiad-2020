#!/usr/bin/env python3
#Place ans candies in one half, then place as many candies as possible in other half, as long as the answer is unique

from __future__ import print_function
import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed = int(cmdlinearg('seed', sys.argv[-1]))
n = int(cmdlinearg('n'))
ans = int(cmdlinearg('ans'))

random.seed(seed)

def getAns(necklace): #hitta bästa som inte är första halvan
    s = sum(necklace[:n//2])
    best = 0
    for i in range(n-1):
        s -= necklace[i]
        s += necklace[(i+n//2)%n]
        best = max(best,s)
    return best

necklace = [0]*n

#Anta att första halvan är bästa, lägg ans bra godisar där 
firstHalfIndex = [i for i in range(1,n//2-1)]
random.shuffle(firstHalfIndex)
firstHalfIndex = [0,n//2-1]+firstHalfIndex
for i in range(ans):
    necklace[firstHalfIndex[i]] = 1


secondHalfIndex = [i for i in range(n//2,n)]
random.shuffle(secondHalfIndex)
l = 0
r = n//2
while l+1<r:
    mid = (l+r)//2
    for i in range(mid):
        necklace[secondHalfIndex[i]] = 1

    if getAns(necklace)>=ans:
        r = mid
    else:
        l = mid

    for i in range(n//2,n):
        necklace[i] = 0

for i in range(l):
    necklace[secondHalfIndex[i]] = 1

#rotera halsbandet slumpmässigt
randomRotation = random.randrange(n)
necklace = necklace[randomRotation:]+necklace[:randomRotation]
print(''.join("VB"[x] for x in necklace))
