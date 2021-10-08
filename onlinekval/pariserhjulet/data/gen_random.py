#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed = int(cmdlinearg('seed', sys.argv[-1]))
random.seed(seed)

n = random.randint(int(cmdlinearg('minN', default=1)), int(cmdlinearg('maxN')))
maxM = cmdlinearg('maxM')
maxM = n if maxM == "n" else int(maxM)
m = random.randint(int(cmdlinearg('minM', default=1)), maxM)
maxT = int(cmdlinearg('maxT'))
minT = int(cmdlinearg('minT', default=1))

T = [random.randint(minT, maxT) for _ in range(n)]

print(n, m)
print(" ".join(map(str, T)))
