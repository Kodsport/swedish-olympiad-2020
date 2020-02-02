#!/usr/bin/python3

import sys
import random

default = {
    "l1": 5,
    "l2": 5,
    "letters": 26,
    "yes": 0,
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
    l2 = int(cmdlinearg("l2"))
    rev = 0
    if l1 < l2:
        t = l1
        l1 = l2
        l2 = t
        rev = 1

    letters = int(cmdlinearg("letters"))
    yes = int(cmdlinearg("yes"))
    k = int(cmdlinearg("k"))
    print(k)
    
    n1 = random.randint(1,l1)
    n2 = random.randint(1,l2)

    if yes == 1:
        n2 = max(n2, n1-l1+l2)
        n2 = min(n2, n1)

    alpha = "abcdefghijklmnopqrstuvwxyz"

    s1 = ""
    s2 = ""

    if yes == 0:
        for _ in range(0,n1):
            s1 += alpha[random.randint(0,letters-1)]
        for _ in range(0,n2):
            s2 += alpha[random.randint(0,letters-1)]
    else:
        ind = []
        for i in range(0,n1):
            s1 += alpha[random.randint(0,letters-1)]
            ind.append(i)
        ind2 = random.sample(ind,n2)
        ind2.sort()
        for i in ind2:
            s2 += s1[i]

    if rev == 1:
        print(s2,l2)
        print(s1,l1)
    else:
        print(s1,l1)
        print(s2,l2)        



            
    
if __name__ == "__main__":
    main()