#!/usr/bin/python3

import sys, random

MAX_ABS_COORD = 10 ** 6
MAX_ABS_DELTA = 10 ** 5

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

N = int(cmdlinearg("n", None))
planeCount = cmdlinearg("planeCount", "many")
starCount = int(cmdlinearg("starCount", "0"))
random.seed(int(sys.argv[-1]))

groupSizes = []
if planeCount == "1":
    groupSizes = [ N - 1, 1 ]
elif planeCount == "0":
    groupSizes = [ N ]
elif starCount:
    groupSizes = [ starCount ] + [ 1 ] * (N - starCount)
else:
    remGS = N
    while remGS > 0:
        s = random.randint(1, remGS)
        groupSizes.append(s)
        remGS -= s

points1, points2, deltas = set(), set(), set()
for s in groupSizes:
    dx, dy = random.randint(-MAX_ABS_DELTA, MAX_ABS_DELTA), random.randint(-MAX_ABS_DELTA, MAX_ABS_DELTA)
    
    minX = max(-MAX_ABS_COORD, -MAX_ABS_COORD - dx)
    minY = max(-MAX_ABS_COORD, -MAX_ABS_COORD - dy)
    maxX = min(MAX_ABS_COORD, MAX_ABS_COORD - dx)
    maxY = min(MAX_ABS_COORD, MAX_ABS_COORD - dy)
    
    while s > 0:
        p1 = (random.randint(minX, maxX), random.randint(minY, maxY))
        p2 = (p1[0] + dx, p1[1] + dy)
        if p1 not in points1 and p2 not in points2:
            points1.add(p1)
            points2.add(p2)
            s -= 1

points1 = list(points1)
points2 = list(points2)
random.shuffle(points1)
random.shuffle(points2)

print(N)
for p in points1:
    print(*p)
for p in points2:
    print(*p)
