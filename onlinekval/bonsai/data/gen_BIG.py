# -*- coding: utf-8 -*-
"""
Created on Sun Nov  3 17:11:50 2019

@author: Mattias Akke
"""
import random
import math
import sys
import queue
from gen_common import *

def gen_tree(n, mode):
    eds = []
    assert mode in ['random', 'star', 'line', 'shallow', 'deep', 'deeper']
    depth = [0]
    for i in range(1, n):
        if mode == 'random':
            pred = random.randrange(i)
        elif mode == 'star':
            pred = 0
        elif mode == 'line':
            pred = i-1
        elif mode == 'shallow':
            pred = int(random.uniform(0, i**0.2) ** 5)
        elif mode == 'deep':
            pred = i-1 - int(random.uniform(0, i**0.1) ** 10)
        elif mode == 'deeper':
            if i < 4:
                pred = random.randrange(i)
            else:
                hi = math.log2(math.log2(i))
                pred = i - int(2 ** 2 ** min(random.uniform(-3, hi), random.uniform(-3, hi), random.uniform(-3, hi)))
        else:
            assert False
        assert 0 <= pred < i
        eds.append((pred, i))
        depth.append(depth[pred] + 1)
    return eds

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n"))
mode = cmdlinearg("mode")
rooted = int(cmdlinearg('rooted'))

eds = gen_tree(n, mode)
tree = [[] for _ in range(n)]
for e in eds:
    x, y = e
    tree[x].append(y)
    tree[y].append(x)

if rooted:
    make_zero_best_root(tree)

print_tree(tree)
