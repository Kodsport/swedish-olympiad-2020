#!/usr/bin/python3

import sys
import random

default = {
    "q": 5,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    q = int(cmdlinearg("q"))
    print("13 3 " + str(q))
    print("0 1 1 2 0 2 1 1 0 1 2 1 0")
    queries = ["1 13", "1 5", "5 9", "9 13", "4 4"]
    for i in range(0,q):
        if i >= len(queries):
            l = random.randint(1,n)
            r = random.randint(1,n)
            print(min(l,r), max(l,r))
        else:
            print(queries[i])

    
if __name__ == "__main__":
    main()

