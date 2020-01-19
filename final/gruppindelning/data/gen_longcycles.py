import random, sys

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n", None))
m = int(cmdlinearg("m", None))
arg = cmdlinearg("arg","-")

print(n,m)
rn = (n+1)//2
ms = random.sample(range(1,rn-1),k=m)
lst = 1

if (arg == "solvable"):
    assert(m%2 == 0)
    m //= 2
    lt = []
    while m > n//7:
        lt.append(random.randint(1,m))
        m -= lt[-1]
    if (m != 0):
        lt.append(m)
    for j in range(len(lt)):
        lt[j] *= 2
    cur = 0
    for i in range(len(lt)):
        lst = 1
        tmp = cur
        for j in range(lt[i]-1):
            diff = random.randint(0,1)
            print(2*ms[cur] - lst, 2*ms[cur+1] - 1 + diff)
            lst = diff
            cur += 1
        print(2*ms[tmp], 2*ms[cur] - lst)
        cur += 1
elif (arg == "several"):
    lt = []
    while m > n//7:
        lt.append(random.randint(1,m))
        m -= lt[-1]
    if (m != 0):
        lt.append(m)
    cur = 0
    for i in range(len(lt)):
        lst = 1
        tmp = cur
        for j in range(lt[i]-1):
            diff = random.randint(0,1)
            print(2*ms[cur] - lst, 2*ms[cur+1] - 1 + diff)
            lst = diff
            cur += 1
        print(2*ms[tmp], 2*ms[cur] - lst)
        cur += 1
else:
    for i in range(m-1):
        diff = random.randint(0,1)
        print(2*ms[i] - lst, 2*ms[i+1] - 1 + diff)
        lst = diff
    print(2*ms[0], 2*ms[-1] - lst)
