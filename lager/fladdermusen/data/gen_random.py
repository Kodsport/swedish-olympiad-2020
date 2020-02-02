import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
N = int(cmdlinearg('N', 10))
Q = int(cmdlinearg('Q', 10))
H = int(cmdlinearg('H', 20))
W = int(cmdlinearg('W', 100))
N1 = int(cmdlinearg('N1', -1))
N2 = int(cmdlinearg('N2', -1))

if N1 >= 0:
    N2 = N-N1
elif N2 >= 0:
    N1 = N-N2
else:
    N1 = int(N/2)
    N2 = N-N1


print(*(N,Q,H,W))

used_x = {0}

def get_unique_x():
    x = random.randint(1,W-1)
    while (x in used_x):
        x = random.randint(1,W-1)
    used_x.add(x)
    return x



cave = []
for i in range(0,N1):
    y = random.randint(1,H-1)
    x = get_unique_x()
    cave.append((1,x,y))

for i in range(0,N2):
    y = random.randint(1,H-1)
    x = get_unique_x()
    cave.append((2,x,y))

assert(len(cave) == N)

random.shuffle(cave)
for a in cave:
    print(*a)

for i in range(0,Q):
    x1 = get_unique_x()
    y1 = random.randint(1,H-1)
    x2 = get_unique_x()
    y2 = random.randint(1,H-1)
    print(*(x1,y1,x2,y2))
