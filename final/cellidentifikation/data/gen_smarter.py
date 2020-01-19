#!/usr/bin/env pypy
from __future__ import print_function
import sys, random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default != None
    return default

random.seed(int(sys.argv[-1]))
k = int(cmdlinearg("k"))
n = int(cmdlinearg("n"))
Q = int(cmdlinearg("q"))
mode = int(cmdlinearg('mode'))

q = [("", 0, 0)]
cands = []
cands2 = []
while q:
    x,y,z = q.pop()
    if len(x) == k:
        if y <= k//2 + 1:
            cands.append(x)
        if y <= k//2:
            cands2.append(z)
    else:
        q.append((x + "0", y, z * 2))
        q.append((x + "1", y + 1, z * 2 + 1))

seqs = set()
while len(seqs) < n:
    seqs.add(random.choice(cands))
cands2 = set(cands2)

seqs = list(seqs)
random.shuffle(seqs)

mins = [n] * (1 << k)
maxs = [-1] * (1 << k)

for i, seq in enumerate(seqs):
    nu = 0
    for c in seq:
        nu = nu * 2 + ord(c) - 48
    if mins[nu] == n:
        mins[nu] = i
    maxs[nu] = i

for b in range((1 << k)-1, -1, -1):
    if mins[b] != n:
        for i in range(k):
            b2 = b & ~(1 << i)
            mins[b2] = min(mins[b2], mins[b])
    if maxs[b] != -1:
        for i in range(k):
            b2 = b & ~(1 << i)
            maxs[b2] = max(maxs[b2], maxs[b])

uniques = []
multi = []
impossible = []
badimpossible = []
for b in range((1 << k)-1, -1, -1):
    if mins[b] == maxs[b]:
        uniques.append(b)
    elif maxs[b] != -1:
        multi.append(b)
    elif b in cands2:
        impossible.append(b)
    else:
        badimpossible.append(b)
random.shuffle(uniques)
random.shuffle(multi)
random.shuffle(impossible)
allseq = uniques + multi + impossible

def itos(b):
    ret = ''
    for j in range(k):
        if b & (1 << j):
            c = '1'
        else:
            c = '0'
        ret = c + ret
    return ret

print("clear0/0/1/>1:", len(badimpossible), len(impossible), len(uniques), len(multi), file=sys.stderr)

print(n, k)
for seq in seqs:
    print(seq)

inseqs = 0
seqs_set = set(seqs)

print(Q)
for qi in range(Q):
    if mode == 1:
        if qi < len(uniques):
            u = uniques[qi]
        else:
            u = random.choice(allseq)
    else:
        if qi < len(impossible):
            u = impossible[qi]
        else:
            if random.randrange(10) == 0:
                u = random.choice(allseq)
            else:
                u = random.choice(uniques)
    se = itos(u)
    print(se)
    if se in seqs_set:
        inseqs += 1

print("Queries that match exactly:", inseqs, file=sys.stderr)
