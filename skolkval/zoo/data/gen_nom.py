import random, sys
import string

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

n = int(cmdlinearg("maxn"))
k = int(cmdlinearg("maxk"))

print(n, k, 0)
