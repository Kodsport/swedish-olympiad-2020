import sys, random

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

mth = [0,31,28,31,30,31,30,31,31,30,31,30,31]

def date(val):
    i = 1
    while val >= mth[i]:
        val -= mth[i]
        i += 1
    mm = str(i)
    dd = str(val+1)
    if (len(mm) == 1):
        mm = "0"+mm
    if (len(dd) == 1):
        dd = "0"+dd
    return dd+"/"+mm

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n", None))
d = int(cmdlinearg("d", random.randint(1,365)))
impossible = int(cmdlinearg("impossible", 0))

print(n,d)
if impossible:
    hi = random.randint(0,364)
    lo = (365+hi-d+1)%365
    while lo > hi:
        hi += 365
    for i in range(n):
        print(date(random.randint(lo,hi)%365))
else:
    for i in range(n):
        print(date(random.randint(0,364)))
