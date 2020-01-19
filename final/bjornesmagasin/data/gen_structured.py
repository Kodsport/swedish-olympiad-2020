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
d = int(cmdlinearg("d", random.randint(350,360)))
k = random.randint(3,10)

print(n,d)
vals = []
for i in range(k):
    diff = random.randint(15,40)
    st = random.randint(0,diff)
    while st < 365:
        vals.append(st)
        st += diff + random.randint(3,10)

for i in range(n):
    j = random.randint(0,len(vals)-1)
    print(date(vals[j]))
