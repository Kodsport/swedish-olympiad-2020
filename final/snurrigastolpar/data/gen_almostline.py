import sys, random

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n", None))
m = int(cmdlinearg("m", 10**9))

print(n)
points = set()
x = random.randint(1,m)
while len(points) < n//10:
    points.add((random.randint(1,m),random.randint(1,m)))
while len(points) < n:
    points.add((x,random.randint(1,m)))
ps = []
for p in points:
    ps.append(p)
random.shuffle(ps)
for p in ps:
    print(p[0],p[1])
