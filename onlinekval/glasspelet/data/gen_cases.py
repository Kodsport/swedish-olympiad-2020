#!/usr/bin/python3

import sys
import random

default = {
    "n": 20,
    "left": 0,
    "right": 0,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    left = int(cmdlinearg("left"))
    right = int(cmdlinearg("right"))

    A = []

    A.append(0)
    ones = (n-2)//2
    twos = (n-2)//2
    if left != ones%2:
        ones -= 1
    if right != twos%2:
        twos -= 1

    for i in range(0,ones):
        A.append(1)
    for i in range(0,twos):
        A.append(2)
    A.append(0)
    print(len(A),3,1)
    print(*A)
    print(1,len(A))
    
if __name__ == "__main__":
    main()

