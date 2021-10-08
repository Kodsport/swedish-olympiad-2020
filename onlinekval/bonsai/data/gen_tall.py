# -*- coding: utf-8 -*-
"""
Created on Sun Nov  3 12:20:56 2019

@author: Mattias Akke
"""

import random
import queue
import sys
from gen_common import *

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n"))
rooted = int(cmdlinearg('rooted'))
randomlist = [1]*random.randint(0, 6) + [2] + [0]

tree = [[] for _ in range(n)]
q = queue.Queue()
perm = list(range(n))
random.shuffle(perm)
v = perm[-1]
del perm[-1]
tree[perm[-1]].append(v)
tree[v].append(perm[-1])
q.put_nowait(perm[-1])
del perm[-1]
tree[perm[-1]].append(v)
tree[v].append(perm[-1])
q.put_nowait(perm[-1])
del perm[-1]

while(len(perm) > 0):
    now = q.get_nowait()
    branches = random.choice(randomlist)
    while(branches == 0 and q.empty()):
        branches = random.choice(randomlist)
    if(len(perm)== 1):
        tree[now].append(perm[0])
        tree[perm[0]].append(now)
        del perm[0]
    else:
        for i in range(branches):
            v = perm[-1]
            del perm[-1]
            q.put_nowait(v)
            tree[now].append(v)
            tree[v].append(now)

make_zero_best_root(tree)
print_tree(tree)
