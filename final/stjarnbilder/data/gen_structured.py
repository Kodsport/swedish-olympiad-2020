#!/usr/bin/python3
# Generate points in a pattern such that A - A is small.
# This could conceivably trigger some worst-case behavior.

import sys, random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default != None
    return default

n = int(cmdlinearg("n"))
k = int(cmdlinearg("k"))
delta = list(map(int, cmdlinearg('delta').split(',')))
random.seed(int(sys.argv[-1]))

print(n)
for _ in range(2):
    lim = 10**4

    bx = random.randint(-lim, lim)
    by = random.randint(-lim, lim)

    ar = [True] * n + [False] * k
    random.shuffle(ar)
    pt = []
    for i in range(len(ar)):
        x = bx + delta[0] * i
        y = by + delta[1] * i
        if ar[i]:
            pt.append((x, y))

    random.shuffle(pt)
    for p in pt:
        print(*p)
