#!/usr/bin/env python3

from common import *
assert(4*n-1 == m)
print(n, m)
for a in range(2,4*n+1):
    #Connect a to random person b < a
    b = random.randrange(1, a)
    print(a,b)
