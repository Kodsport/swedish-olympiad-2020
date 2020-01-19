import random
import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

def print_tree(n,m,k,eds,shuffle_nodes=True):
    assert len(eds) == n-1
    ren = list(range(1, n+1))
    if shuffle_nodes:
        random.shuffle(ren)
    random.shuffle(eds)
    print(n,m,ren[k])
    for (x,y) in eds:
        if random.choice([True, False]):
            x,y = y,x
        print(ren[x], ren[y])

random.seed(int(cmdlinearg("seed", sys.argv[-1])))
