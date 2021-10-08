import sys
import queue
import random
from math import *
from gen_common import *

random.seed(int(sys.argv[-1]))
maxT = int(cmdlinearg("maxt"))
randlist = [0] + [1] * random.randint(0, 4)
treeAdj = [[]]

MIN_NEW_LEAVES = 0.5
MAX_NEW_LEAVES = 0.9

for t in range(maxT):
    giveNewLeaf = list(range(len(treeAdj)))
    random.shuffle(giveNewLeaf)
    numNewLeaves = int(ceil(random.uniform(MIN_NEW_LEAVES, MAX_NEW_LEAVES) * len(giveNewLeaf)))
    for node in giveNewLeaf[:numNewLeaves]:
        treeAdj[node].append(len(treeAdj))
        treeAdj.append([node])

perm = list(range(len(treeAdj)))
random.shuffle(perm)
pTreeAdj = [[] for _ in range(len(treeAdj))]
for i, l in enumerate(treeAdj):
    j = perm[i]
    l2 = [perm[x] for x in l]
    pTreeAdj[j] = l2

make_zero_best_root(pTreeAdj)
print_tree(pTreeAdj)
