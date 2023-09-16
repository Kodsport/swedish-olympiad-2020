import random, sys

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

S = [1, 1]
for _ in range(int(cmdlinearg("n", 0))):
    S.append(S[-1] + S[-2])
print(sum(S))
