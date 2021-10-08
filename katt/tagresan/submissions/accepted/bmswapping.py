#!/usr/bin/env pypy
import sys
sys.setrecursionlimit(1000000)

def dfs(cur):
    if flags[cur]:
        return
    flags[cur] = True
    dfsorder.append(cur)
    for nei in neis[cur]:
        dfs(nei)
t = input()
n,m = map(int, raw_input().split())
edgs = []
neis = [[] for i in range(4*n)]
for i in range(m):
    a,b = map(int, raw_input().split())
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
        output[-1].append(dfsorder[4*i+j])
        id_to_pos[dfsorder[4*i+j]] = (i,j)
#Begin swapping
for i1 in range(n):
    for j1 in range(4):
        for i2 in range(i1-10,i1+10):
            if i2<0 or i2>=n: continue
            for j2 in range(4):
                a = output[i1][j1]
                b = output[i2][j2]
                tot = 0
                for nei in neis[a]:
                    if nei==b: continue #avoid division by 0
                    iny,jny=id_to_pos[nei]
                    tot +=1/((iny-i1)**2+(jny-j1)**2) #1/L**2
                    tot -=1/((iny-i2)**2+(jny-j2)**2) #dist after swap
                for nei in neis[b]:
                    if nei==a: continue
                    iny,jny=id_to_pos[nei]
                    tot -=1/((iny-i1)**2+(jny-j1)**2)
                    tot +=1/((iny-i2)**2+(jny-j2)**2)
                if tot < 0:
                    output[i1][j1]=b
                    output[i2][j2]=a
                    id_to_pos[a]=(i2,j2)
                    id_to_pos[b]=(i1,j1)

for i in range(n):
    print (' '.join(map(lambda x: str(x+1), output[i])))
