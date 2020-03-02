#!/usr/bin/env python3

from common import *
#Define variable k that is the number of stars
#Let first k nodes be centers of stars, connect the other nodes randomly to them.
k = int(cmdlinearg('k'))
assert(4*n == m+k)
print(n, m)
for a in range(k+1,4*n+1):
    #Connect a to random star b
    b = random.randrange(0, k) + 1
    print(a,b)
