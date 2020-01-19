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
X = set()
Y = set()
x = []
y = []
points = set()
k = math.floor(n**0.5)
while (len(X) < k):
    X.add(random.randint(1,m))
while (len(Y) < k):
    Y.add(random.randint(1,m))
for xi in X:
    x.append(xi)
for yi in Y:
    y.append(yi)

while (len(points) < n):
    if (random.randint(1,2) == 1):
        points.add((x[random.randint(0,k-1)],random.randint(1,m)))
    else:
        points.add((random.randint(1,m), y[random.randint(0,k-1)]))

ps = []
for p in points:
    ps.append(p)
random.shuffle(ps)
for p in ps:
    print(p[0],p[1])
