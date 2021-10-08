#!/usr/bin/env pypy
import sys
import random
sys.setrecursionlimit(1000000)
#swap elements in v one time if beneficial (it's buggy for len(v) > 2)
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
#Idea I had to scramble people and move them in the direction of their neighbours
#First one seems to destroy solution a lot. Running multiple times gives slightly
#better result but is time-consuming.
def average_grid():
    new_pos = []

    for a in range(4*n):
        i,j=id_to_pos[a]
        for nei in neis[a]:
            di,dj=id_to_pos[nei]
            i,j=i+di,j+dj
        i=float(i)/(len(neis[a])+1.0)
        j=float(j)/(len(neis[a])+1.0)
        new_pos.append((i,j,a))
    new_pos.sort()
    for i in range(n):
        row = new_pos[4*i:4*i+4]
        row.sort(key=lambda x: x[1])
        for j in range(4):
            output[i][j]=row[j][2]
            id_to_pos[row[j][2]] = (i,j)

#Used by me to isolate cases
def identity():
    for i in range(n):
        print 4*i+4, 4*i+1, 4*i+2, 4*i+3
    exit(0)

#Create some reasonable initial state by distributing in dfsorder.
def place_dfs():
    global output, id_to_pos
    def dfs(cur):
        if flags[cur]:
            return
        flags[cur] = True
        dfsorder.append(cur)
        for nei in neis[cur]:
            dfs(nei)
    dfsorder = []
    flags = [False for i in range(4*n)]
    order = [i for i in range(4*n)]
    order.sort(key = lambda a: len(neis[a]))
    for a in order:
        dfs(a)
    for i in range(n):
        output.append([])
        for j in range(4):
            if i%2 == 0:
                output[-1].append(dfsorder[4*i+j])
                id_to_pos[dfsorder[4*i+j]] = (i,j)
            else:
                output[-1].append(dfsorder[4*i+3-j])
                id_to_pos[dfsorder[4*i+3-j]] = (i,j)

def inbound(i,j):
    return 0<=i<n and 0<=j<4

def adjacent(i,j):
    out = []
    for di in range(-1,2):
        for dj in range(-1,2):
            #Removing diagonal tiles like this improved things slightly.
            if di!=0 and dj!=0:
                continue
            if inbound(i+di,j+dj):
                out.append((i+di,j+dj))
    return out
#Traverse both relationshipgraph and adjacency graph in train.
#Place nodes as you go. (Good for testcase 10)
def place_trav():
    global output, id_to_pos
    def place_node(cur, i, j):
        output[i][j]=cur
        id_to_pos[cur]=(i,j)
        flags[cur]=True
        avaliable.remove((i,j))
        #Switching order of these loops gives much worse result.
        for nei in neis[cur]:
            for ni,nj in adjacent(i,j):
                if flags[nei]:
                    break
                if (ni,nj) not in avaliable:
                    continue
                place_node(nei,ni,nj)

    flags = [False for i in range(4*n)]
    output = [[-1 for j in range(4)] for i in range(n)]
    avaliable = set()
    for i in range(n):
        for j in range(4):
            avaliable.add((i,j))
    firstavaliable=0
    order = [i for i in range(4*n)]
    order.sort(key = lambda a: len(neis[a]))
    for a in order:
        while (firstavaliable/4,firstavaliable%4) not in avaliable:
            firstavaliable+=1
            if firstavaliable>=4*n: break
        if flags[a] or (firstavaliable/4,firstavaliable%4) not in avaliable:
            continue
        place_node(a,firstavaliable/4,firstavaliable%4)



t = input()
n,m = map(int, raw_input().split())
# if t<9:
#     identity()
edgs = []
neis = [[] for i in range(4*n)]
for i in range(m):
    a,b = map(int, raw_input().split())
    a-=1
    b-=1
    edgs.append((a,b))
    neis[a].append(b)
    neis[b].append(a)
#Sort neighbours so that ones with low degree are picked first.
#Seems to increase score by 10-15 for place_dfs.
for i in range(4*n):
    neis[i].sort(key = lambda n: len(neis[n]))

global output, id_to_pos
output = []
id_to_pos = [-1 for i in range(4*n)]
if t<9:
    place_dfs()
else:
    place_trav()
#Begin swapping

for i1 in range(n):
    for j1 in range(4):
        for i2 in range(i1-2,i1+2):
            if i2<0 or i2>=n: continue
            for j2 in range(4):
                a = output[i1][j1]
                b = output[i2][j2]
                swap((a,b))
# for a,b in edgs:
#     swap((a,b))
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
