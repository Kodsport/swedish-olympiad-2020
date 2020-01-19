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
k = int(cmdlinearg("k", random.randint(1,n)))
impossible = int(cmdlinearg("impossible", 0))


bj = random.randint(0,364)

day = set()
days = []
while len(day) < k:
    day.add(random.randint(0,364))

for i in day:
    days.append(i)
days.sort()

md = 0
for i in range(len(days)-1):
    md = max(md,days[i+1]-days[i])
md = max(md,365+days[0]-days[-1])
d = 365 - md

print(n,d)
print(date(bj))
for i in range(n-1):
    print(date(days[random.randint(0,k-1)]))
