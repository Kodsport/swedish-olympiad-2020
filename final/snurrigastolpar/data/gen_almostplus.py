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
y = random.randint(1,m)
while len(points) < n - n//7:
    if (random.randint(1,2) == 1):
        points.add((x,random.randint(1,m)))
    else:
        points.add((random.randint(1,m),y))

while len(points) < n:
    points.add((random.randint(1,m),random.randint(1,m)))

ps = []
for p in points:
    ps.append(p)
random.shuffle(ps)
for p in ps:
    print(p[0],p[1])
