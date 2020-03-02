#!/usr/bin/env python3

from common import *

print(n, m)
edges = set()
for i in range(m):
    a = random.randrange(0, 4*n) + 1
    b = random.randrange(0, 4*n) + 1
    while a == b or 4*a*n+b in edges:
        a = random.randrange(0, 4*n) + 1
        b = random.randrange(0, 4*n) + 1
    edges.add(4*a*n+b)
    edges.add(4*b*n+a)
    print(a,b)
