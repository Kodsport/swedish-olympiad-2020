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
gap = int(cmdlinearg('gap', 0))
prob1 = float(cmdlinearg('prob1', 0.5))
same_direction = int(cmdlinearg('same_direction', 0))
reverse = int(cmdlinearg('reverse', 0))

W = H

def clamp(x, a, b): return max(a, min(x, b))

gap1 = int(gap/2)
gap2 = gap-gap1

print(*(N,Q,H,W))

used_x = {0}

def get_unique_x():
    x = random.randint(1,W-1)
    while (x in used_x):
        x = random.randint(1,W-1)
    used_x.add(x)
    return x


cave = []
for i in range(0,N):
    x = get_unique_x()
    t = 1 if random.random() <= prob1 else 2
    y = x
    if reverse:
        y = H-y
    if t == 1:
        y = clamp(y-gap1, 1, H-1);
    if t == 2:
        if not same_direction:
            y = H-y
        y = clamp(y+gap2, 1, H-1);
    cave.append((t,x,y))

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


