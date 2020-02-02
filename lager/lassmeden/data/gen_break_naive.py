import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
shuffle = int(cmdlinearg('shuffle',0))
print(2*10**5,2*10**5)
ans_no = [random.randint(1,2*10**5) for _ in range(100)]
bs = list(range(200,2*10**5+1))
out = []
for _ in range(10**5):
    r = random.randint(0,len(bs)-1)
    b = bs[r]
    bs[r] = bs[-1]
    bs.pop()
    a = random.randint(0,b-1)
    redo = False
    for ano in ans_no:
        if ano%b==a: redo=True
    while redo:
        a = random.randint(0,b-1)
        redo = False
        for ano in ans_no:
            if ano%b==a: redo=True
    out.append((2,a,b))
for i in range(10**5):
    if i % 2: 
        out.append((1,random.randint(1,2*10**5)))
    else:
        out.append((1,ans_no[random.randint(0,99)]))
if shuffle: random.shuffle(out)
for o in out: print(' '.join(map(str,o)))
