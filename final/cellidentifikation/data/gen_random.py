#!/usr/bin/python3

import sys
import random

default = {
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def gen_string(k, weight, used):
    s = "".join(random.choices("01", k=k, weights=[weight, 1]))
    if used is not None:
        if s in used:
            return gen_string(k, weight, used)
        used.add(s)
    return s

def main():
    random.seed(int(sys.argv[-1]))

    n = int(cmdlinearg("n"))
    k = int(cmdlinearg("k"))
    q = int(cmdlinearg("q"))

    print(n, k)
    used = set()
    for i in range(n):
        print(gen_string(k, 3, used))

    print(q)
    for i in range(q):
        print(gen_string(k, 6, None))


if __name__ == "__main__":
    main()
