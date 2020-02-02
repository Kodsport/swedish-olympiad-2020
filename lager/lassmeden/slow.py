from collections import *
import sys
try:
    inp = raw_input
except:
    inp = input

def err(s):
    sys.stderr.write('{}\n'.format(s))

def ni():
    return int(inp())

def nl():
    return map(int, inp().split())

N, Q = nl()

sq = 250

KEYS = [[0]*i for i in range(sq)]

LOCKS = [0]*(N + 1)

out = []

ones = 0
for _ in range(Q):
    CMD = nl()
    c = CMD[0]
    if c == 1:
        ones += 1
        if ones > 8000:
            break
        x = CMD[1]
        ok = bool(LOCKS[x])
        for m in range(1, sq):
            ok = ok or bool(KEYS[m][x%m])
        out.append('ja' if ok else 'nej')
    elif c == 2:
        a, b = CMD[1:]
        if b >= sq:
            for v in range(a, N+1, b):
                LOCKS[v] += 1
        else:
            KEYS[b][a] += 1
    else:
        a, b = CMD[1:]
        if b >= sq:
            for v in range(a, N+1, b):
                LOCKS[v] -= 1
        else:
            KEYS[b][a] -= 1
print('\n'.join(out))
