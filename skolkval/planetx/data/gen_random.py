import random, sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))

n = int(cmdlinearg("maxn", 10))
m = int(cmdlinearg("maxm", 10))

dens = int(cmdlinearg("dens"))

G = [[random.randint(0, 9) for _ in range(m)] for _ in range(n)]

x = [(i, j) for i in range(n) for j in range(m)]
random.shuffle(x)

for r, c in x:
    for nr in range(n):
        for nc in range(m):
            G[nr][nc] = max(G[nr][nc], G[r][c] - abs(r - nr) - abs(c - nc))
            G[nr][nc] = min(G[nr][nc], G[r][c] + abs(r - nr) + abs(c - nc))

for _ in range(n * m * (100 - dens) // 100):
    G[random.randint(0, n - 1)][random.randint(0, m - 1)] = '.'

print(n, m)
for i in range(n):
    print(''.join(str(x) for x in G[i]))
