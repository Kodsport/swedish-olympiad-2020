import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

N = int(cmdlinearg('N',200000))
Q = 3
num_to_break = int(cmdlinearg('toBreak'))
assert 0 < num_to_break <= N

print(N,Q)
print(1,num_to_break)
print(2,num_to_break%33333,33333)
print(1,num_to_break)
