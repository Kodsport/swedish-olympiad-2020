import random, sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

n = int(cmdlinearg("n"))
m = int(cmdlinearg("m"))

print(n, m)
print('1' + '.' * (m-1))
for _ in range(n-1):
    print('.' * m)
