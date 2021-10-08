#!/usr/bin/python3

import sys
import random

default = {
    "n": 20,
    "k": 5,
    "q": 5,
    "mode": "random",
    "intervals": "random",
    "x": 4,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    k = int(cmdlinearg("k"))
    q = int(cmdlinearg("q"))
    mode = (cmdlinearg("mode"))
    intervals = (cmdlinearg("intervals"))
    x = int(cmdlinearg("x"))
    A = []
    if mode == "random":
        for i in range(0,k):
            A.append(i)
        for i in range(0,n-k):
            A.append(random.randint(0,k-1))
        random.shuffle(A)

    if mode == "double":
        # There are only 2 zeros, on positions x and n-x-1, creating a
        # double ended "critical state" [x,n-x-1].
        for i in range(1,k):
            A.append(i)
        for i in range(0,n-k-1):
            A.append(random.randint(1,k-1))
        random.shuffle(A)
        A.append(0)
        A.append(0)
        temp = A[x]
        A[x] = A[n-2]
        A[n-2] = temp
        temp = A[n-x-1]
        A[n-x-1] = A[n-1]
        A[n-1] = temp

    if mode == "manyzeros":
        # There are exactly x zeros.
        for i in range(1,k):
            A.append(i)
        for i in range(0,x):
            A.append(0)
        while len(A) < n:
            A.append(random.randint(1,k-1))
        random.shuffle(A)

    if mode == "smart":
        # First setting A[i] to i%k. Then adding a few random ice creams at the end.
        # This should make many intervals valid
        A = [i%k for i in range(max(n*3//4, k))]
        while len(A)  < n:
	        A.append(random.randrange(k))
    
    print(n,k,q)
    print(*A)

    if intervals == "random":
        for i in range(0,q):
            l = random.randint(1,n)
            r = random.randint(1,n)
            print(min(l,r), max(l,r))
    
    if intervals == "same":
        for i in range(0,q):
            print(1,n)
    
    if intervals == "symmetric":
        for i in range(0,q):
            x2 = random.randint(1, n//2)
            print(x2, n-x2+1)
    
    if intervals == "small":
        for i in range(0,q):
            l = random.randint(1, n)
            r = random.randint(l, l+k)
            if random.randint(1,3) == 3:
                r = l+k
            if random.randint(1,4) == 4:
                r = l+k-1
            r = min(n,r)
            print(l, r)
    
if __name__ == "__main__":
    main()

