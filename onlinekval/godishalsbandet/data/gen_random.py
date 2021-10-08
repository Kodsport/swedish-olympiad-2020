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
n = int(cmdlinearg('n'))
r = float(cmdlinearg('r'))

random.seed(seed)

necklace = ""

for i in range(n):
    if random.uniform(0,1)<r:
        necklace += "B"
    else:
        necklace += "V"

print(necklace)
