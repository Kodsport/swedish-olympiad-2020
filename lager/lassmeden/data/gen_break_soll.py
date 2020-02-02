import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
print(2*10**5,2*10**5)
keys = []
for i in range(66663):
    b = random.randint(2,20)
    a = random.randint(0,b-1)
    print(2,a,b)
    keys.append((a,b))
    if i%2 == 0:
        b = random.randint(2,20)
        a = random.randint(0,b-1)
        print(2,a,b)
        keys.append((a,b))
    else:
        k = keys.pop()
        print(3,k[0],k[1])
    k = keys.pop()
    print(3,k[0],k[1])

for _ in range(11):
    print(1,random.randint(1,2*10**5))
