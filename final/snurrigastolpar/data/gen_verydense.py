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
mym = min(random.randint(math.ceil(n**0.5),math.ceil(n**0.5)+3),m)


while len(points) < mym*mym-n:
    points.add((random.randint(1,mym),random.randint(1,mym)))

for x in range(1,mym+1):
    for y in range(1,mym+1):
        if (x,y) not in points:
            print(x,y)
