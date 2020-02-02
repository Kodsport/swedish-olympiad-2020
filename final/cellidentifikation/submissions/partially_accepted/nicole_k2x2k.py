#!/usr/bin/env python3
import copy
import sys

sys.setrecursionlimit(1000000000)
N,K = map(int, input().split())

graph = [[] for _ in range(2**K)]

def to_binary(x):
    bin = [0 for _ in range(K)]
    for i in range(K):
        bin[i] = x%2
        x//=2
    return bin

def to_number(bin):
    x = 0
    for i in range(K-1, -1, -1):
        x*=2
        x += bin[i]
    return x

for i in range(2**K):
    s = to_binary(i)
    for j in range(K):
        if s[j] == 0:
            a = copy.deepcopy(s)
            a[j] = 1
            graph[i].append(to_number(a))

ans = [set() for _ in range(2**K)]
for i in range(N):
    s = input()
    b = [int(s[j]) for j in range(K)]
    ans[to_number(b)].add(i)

def get_new_graph_value(x):
    for y in graph[x]:
        g = get_new_graph_value(y)
        for z in g:
            ans[x].add(z)
    if len(ans[x]) > 2:
        temp = set()
        for z in ans[x]:
            if len(temp) > 2:
                break
            temp.add(z)
    return ans[x]

get_new_graph_value(0)

Q = int(input())
for _ in range(Q):
    s = input()
    b = [int(s[j]) for j in range(K)]
    a = to_number(b)
    if len(ans[a]) == 0:
        print('finns ej')
    elif len(ans[a]) > 1:
        print('vet ej')
    else:
        for x in ans[a]:
            print(x+1)
