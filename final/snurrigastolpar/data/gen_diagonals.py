import sys, random, math

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
while len(points) < n:
    k = random.randint(1,m)
    if (random.randint(1,2) == 1):
        points.add((k, max(1,min(k+random.randint(-2,2),m))))
    else:
        points.add((k, max(1,min(m-k+random.randint(-2,2),m))))

ps = []
for p in points:
    ps.append(p)
random.shuffle(ps)
for p in ps:
    print(p[0],p[1])
