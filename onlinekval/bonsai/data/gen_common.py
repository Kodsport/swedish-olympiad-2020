import random
import queue
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

def find_best_root(tree):
     steps, bt = [], []
     pq = queue.PriorityQueue()
     for ind, line in enumerate(tree):
         m = len(line)
         if m == 1:
             pq.put_nowait((0,ind))
         bt.append(m)
         steps.append(0)
     
     lst = 0
     while pq.empty() == 0:
         _, node = pq.get()
         lst = node
         for i in range(len(tree[node])):
             bt[tree[node][i]] -= 1
             if steps[tree[node][i]] < steps[node] + 1:
                 steps[tree[node][i]] = steps[node] + 1
             else:
                 steps[tree[node][i]] += 1
             if bt[tree[node][i]] == 1:
                 pq.put((steps[tree[node][i]], tree[node][i]))
     return lst

def make_zero_best_root(tree):
    rootNode = find_best_root(tree)
    tree[0], tree[rootNode] = tree[rootNode], tree[0]
    for edges in tree:
        for i in range(len(edges)):
            if edges[i] == 0:
                edges[i] = rootNode
            elif edges[i] == rootNode:
                edges[i] = 0

def print_tree(tree):
    print(len(tree))
    for l in tree:
        print(len(l), ' '.join(map(str, l)))
