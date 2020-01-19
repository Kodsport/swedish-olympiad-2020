#!/usr/bin/python3

import random
from common import cmdlinearg, print_tree

def main():
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    k = int(cmdlinearg("k")) - 1
    edges = []
    for i in range(1, n):
        if i%2 == 1:
            edges.append((i, i-1))
        else:
            edges.append((i, i-2))
    print_tree(n, m, k, edges)

if __name__ == "__main__":
    main()
