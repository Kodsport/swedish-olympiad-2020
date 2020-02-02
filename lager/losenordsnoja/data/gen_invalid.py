#!/usr/bin/python3

import sys
import random

default = {
    "l1": 10,
    "l2": 7,
    "letters": 26,
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
    k = int(cmdlinearg("k"))
    print(k)

    n1 = random.randint(1,l1-1)
    maxn2 = n1 - l1 + l2 - 1
    if maxn2 < 1:
        n2 = n1 + 1
        l2 = n2
    else:
        n2 = random.randint(1,min(l2, maxn2))

    alpha = "abcdefghijklmnopqrstuvwxyz"

    s1 = ""
    s2 = ""

    ind = []
    for i in range(0,n1):
        s1 += alpha[random.randint(0,letters-1)]
        ind.append(i)
    ind2 = random.sample(ind,min(n2, n1))
    ind2.sort()
    for i in ind2:
        s2 += s1[i]
    while len(s2) < n2:
        s2 += 'a'

    if rev == 1:
        print(s2,l2)
        print(s1,l1)
    else:
        print(s1,l1)
        print(s2,l2)        



            
    
if __name__ == "__main__":
    main()