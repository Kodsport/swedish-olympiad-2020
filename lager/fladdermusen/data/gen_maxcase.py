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
H = int(cmdlinearg('H', 1000000000))
W = int(cmdlinearg('W', 1000000000))
space = int(cmdlinearg('space', 2))
top = int(cmdlinearg('top', 10))
bot = int(cmdlinearg('bot', 10))


print(*(N,Q,H,W))

HALF_N = int(N/2)

cave = []
for i in range(0,HALF_N):
    t = (i%2) + 1
    x = space*(i+1)
    if t == 1:
        y = random.randint(H-top,H-1)
    if t == 2:
        y = random.randint(1,bot)
    cave.append([t,x,y])

for i in range(0,N-HALF_N):
    t = (i%2) + 1
    x = W - space*(i+1)
    if t == 1:
        y = random.randint(H-top,H-1)
    if t == 2:
        y = random.randint(1,bot)
    cave.append([t,x,y])

random.shuffle(cave)
for a in cave:
    print(*a)

queriesL = []
queriesR = []
for i in range(0,Q):
    l = space*i + random.randint(1, space-1)
    r = W - space*i - random.randint(1, space-1)
    yl = random.randint(1,H-1)
    yr = random.randint(1,H-1)
    queriesL.append([l,yl])
    queriesR.append([r,yr])

random.shuffle(queriesL)
random.shuffle(queriesR)

for a,b in zip(queriesL,queriesR):
    print(*(a[0],a[1],b[0],b[1]))
