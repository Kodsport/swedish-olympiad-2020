#!/usr/bin/python3

import sys
import random

default = {
    "l1": 20,
    "kind": 0,
    "k": 1,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    l1 = int(cmdlinearg("l1"))
    kind = int(cmdlinearg("kind"))
    k = int(cmdlinearg("k"))
    print(k)

    if kind == 0:
        print('a', l1+2)
        print('a'*(l1-1),l1)      
    else:
        print('a'*(l1-1), l1-1)
        print('a'*(l1-1), l1) 



            
    
if __name__ == "__main__":
    main()