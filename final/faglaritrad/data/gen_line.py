#!/usr/bin/python3

import random
from common import cmdlinearg, print_tree

def main():
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    k = int(cmdlinearg("k")) - 1
    print_tree(n, m, k, [(i, i+1) for i in range(n-1)], shuffle_nodes=False)

if __name__ == "__main__":
    main()
