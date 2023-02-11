#!/usr/bin/env pypy
import sys
import random
sys.setrecursionlimit(1000000)
#swap elements in v one time if beneficial (it's not bulletproof though)
def swap(v):
    tot = 0
    for i,a in enumerate(v):
        b = v[(i+1)%len(v)]
        i_a,j_a = id_to_pos[a]
        i_b,j_b = id_to_pos[b]
        for nei in neis[a]:
            if nei==b: continue #avoid division by 0
            i_n,j_n=id_to_pos[nei]
            tot +=1/((i_n-i_a)**2+(j_n-j_a)**2) #1/L**2
            tot -=1/((i_n-i_b)**2+(j_n-j_b)**2) #dist after swap
    if tot < 0:
        i_s,j_s = id_to_pos[v[0]]
        for i,a in enumerate(v):
            if i == len(v)-1:
                output[i_s][j_s]=a
                id_to_pos[a]=(i_s,j_s)
                break
            i_b,j_b = id_to_pos[v[(i+1)%len(v)]]
            output[i_b][j_b] = a
            id_to_pos[a]=(i_b,j_b)


def dfs(cur):
    if flags[cur]:
        return
    flags[cur] = True
    dfsorder.append(cur)
    for nei in neis[cur]:
        dfs(nei)
t = input()
n,m = map(int, input().split())
edgs = []
neis = [[] for i in range(4*n)]
for i in range(m):
    a,b = map(int, input().split())
    a-=1
    b-=1
    edgs.append((a,b))
    neis[a].append(b)
    neis[b].append(a)
#Create some reasonable initial state by distributing in dfsorder
dfsorder = []
flags = [False for i in range(4*n)]
for i in range(4*n):
    dfs(i)
output = []
id_to_pos = {}
for i in range(n):
    output.append([])
    for j in range(4):
        if i%2 == 0:
            output[-1].append(dfsorder[4*i+j])
            id_to_pos[dfsorder[4*i+j]] = (i,j)
        else:
            output[-1].append(dfsorder[4*i+3-j])
            id_to_pos[dfsorder[4*i+3-j]] = (i,j)
#Begin swapping
for a,b in edgs:
    swap((a,b))
for i1 in range(n):
    for j1 in range(4):
        for i2 in range(i1-2,i1+2):
            if i2<0 or i2>=n: continue
            for j2 in range(4):
                a = output[i1][j1]
                b = output[i2][j2]
                swap((a,b))

for i in range(100000):
    a=random.randrange(0,4*n)
    b=random.randrange(0,4*n)
    swap((a,b))
for i1 in range(n-1,-1,-1):
    for j1 in range(4):
        for i2 in range(i1-2,i1+2):
            if i2<0 or i2>=n: continue
            for j2 in range(4):
                a = output[i1][j1]
                b = output[i2][j2]
                swap((a,b))


for i in range(n):
    print (' '.join(map(lambda x: str(x+1), output[i])))
