import random, sys

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

n = random.randint(2, 10)
l = random.randint(1, 100)
s = random.randint(1, 100)
c = random.randint(1, 100)

print(n, l)
for _ in range(n):
    print(s, c)
