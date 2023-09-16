import random, sys
import string

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

n = random.randint(2, int(cmdlinearg("maxn", 15)))
k = random.randint(2, int(cmdlinearg("maxk", 10)))
m = random.randint(0, int(cmdlinearg("maxm", 5)))

print(n, k, m)
for _ in range(m):
    print(''.join(random.sample(string.ascii_uppercase[:k], random.randint(2, k))))
