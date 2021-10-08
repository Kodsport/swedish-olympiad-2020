#!/usr/bin/python3

from itertools import groupby
s = input()
consonants = "bcdfghjklmnpqrstvwxz"
groups = [''.join(list(g)) for k, g in groupby(s)]
out = ''.join(g[:2] if g[0] in consonants else g for g in groups)
print(out)
