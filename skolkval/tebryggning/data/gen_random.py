import random, sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

k = random.randint(1, int(cmdlinearg("maxk", 10)))
n = random.randint(1, 100)

print(k, n)
N = [random.randint(1, 100) for _ in range(k)]
while sum(N) < n:
    N[random.randint(0, k - 1)] += 1
print(*N)
