#!/usr/bin/python3

import random
from common import cmdlinearg, print_tree

def main():
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    k = int(cmdlinearg("k")) - 1
    print_tree(n, m, k, [(0,i) for i in range(1, n)])

if __name__ == "__main__":
    main()
