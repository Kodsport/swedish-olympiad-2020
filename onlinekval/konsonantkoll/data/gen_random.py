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

def main():
    random.seed(int(sys.argv[-1]))

    n = int(cmdlinearg("n"))
    max_repeated = int(cmdlinearg("maxRepeated"))
    allowSpaces = cmdlinearg("allowSpaces") == "1"

    s = ""
    nonconsonants = "aeiouy"
    consonants = "bcdfghjklmnpqrstvwxz"
    while len(s) < n:
        if random.random() < 0.5:
            s += ''.join(random.choices(nonconsonants, k=random.randint(1, 10)))
        else:
            if random.random() < 0.3:
                c = random.choice(consonants)
                if s == "" or s[-1] != c:
                    s += c
            elif allowSpaces and random.random() < 0.2 and len(s) != 0 and s[-1] != ' ':
                s += ' '
            else:
                c = random.choice(consonants) * random.randint(1, max_repeated)
                if s == "" or s[-1] != c[0]:
                    s += c
    print(s[:n-1].strip())

if __name__ == "__main__":
    main()

