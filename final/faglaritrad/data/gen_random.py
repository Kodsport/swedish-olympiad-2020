#!/usr/bin/python3

import random
from common import cmdlinearg, print_tree

def main():
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    width = int(cmdlinearg("width", 10**5))
    leaf = int(cmdlinearg("leaf", 0))
    nonleaf = int(cmdlinearg("nonleaf", 0))

    nodes = list(range(0,n))
    random.shuffle(nodes)
    parent = [-1]*n
    degree = [0]*n
    for i in range(1, n):
        j = random.randint(max(0, i - width), i - 1)
        parent[nodes[i]] = nodes[j]
        degree[nodes[i]] += 1
        degree[nodes[j]] += 1

    leaves = []
    nonleaves = []
    for i in range(0,n):
        if degree[i] == 1:
            leaves.append(i)
        else:
            nonleaves.append(i)

    k = random.randrange(n)
    if leaf == 1:
        k = random.choice(leaves)
    if nonleaf == 1 and nonleaves:
        k = random.choice(nonleaves)

    eds = []
    for i in nodes[1:n]:
        eds.append((i, parent[i]))

    print_tree(n, m, k, eds)

if __name__ == "__main__":
    main()
