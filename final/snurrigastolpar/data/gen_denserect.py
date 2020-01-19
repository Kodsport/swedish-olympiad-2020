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
bigx = int(cmdlinearg("bigx",0))

print(n)
points = set()
mym = min(random.randint(6,9),m)
mymb = math.ceil(n/mym)+2

while len(points) < mymb*mym-n:
    points.add((random.randint(1,mym),random.randint(1,mymb)))

for x in range(1,mym+1):
    for y in range(1,mymb+1):
        if (x,y) not in points:
            if bigx:
                print(y,x)
            else:
                print(x,y)
