#!/usr/bin/python3

import sys
import random
from solve import solve

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    #return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    onlyForward = cmdlinearg("onlyForward")=="True"
    
    g = random.randint(1,1e2)
    MAX_SPEED = 1e2

    band = []

    for i in range(n):
        a=0
        b=0
        while True:
            a = random.randint(0,m-1)
            b = random.randint(0,m-1)
            if a!=b:
                break
        band.append([min(a,b),max(a,b),random.randint(1,MAX_SPEED)])

    if onlyForward:


        dn = 1
        up = len(band)

        while dn+1<up:#binärsök efter minsta antalet band att ta bort så att det räcker att bara gå framåt
            mid = (dn+up)//2
            if solve(n,m,g,band[:mid],onlyForward=True)==solve(n,m,g,band[:mid]):
                dn = mid
            else:
                up = mid
        band = band[:dn]
        #assert(solve(n,m,g,band,onlyForward=True)==solve(n,m,g,band))

        #assert(solve(n,m,g,band,onlyForward=True)==solve(n,m,g,band))

    random.shuffle(band)
    print(len(band),m,g)
    for b in band:
        print(b[0]+1,b[1]+1,b[2])
    
    #print("ans1: ", solve(n,m,g,band,onlyForward=True))
    #print("ans2: ", solve(n,m,g,band))


if __name__ == "__main__":
    main()

