#!/usr/bin/python3

import random
from common import cmdlinearg, print_tree

def main():
    n = int(cmdlinearg("n"))
    m = n - 1
    k = n - 1
    edges = []
    for i in range(0, n-2):
        edges.append((i, i+1))
    edges.append((n//2 - 1, n-1))
    print_tree(n, m, k, edges)

if __name__ == "__main__":
    main()
