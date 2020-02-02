#!/usr/bin/env python3
import sys
n,k = map(int, input().split())
Ks = (1<<k)

ma = [-1]*Ks
mi = [n]*Ks

def to_dec(s):
    tmp = 0
    for c in s:
        tmp *= 2
        if c == '1':
            tmp += 1
    return tmp

for i in range(n):
    s = input()
    tmp = to_dec(s)
    ma[tmp] = max(ma[tmp],i)
    mi[tmp] = min(mi[tmp],i)

for i in range(Ks-1,-1,-1):
    for j in range(k):
        ma[i] = max(ma[i], ma[i|(1<<j)])
        mi[i] = min(mi[i], mi[i|(1<<j)])

q = int(input())
for i in range(q):
    tmp = to_dec(input())
    if mi[tmp] == ma[tmp]:
        print(mi[tmp]+1)
    elif mi[tmp] > ma[tmp]:
        print('finns ej')
    else:
        print('vet ej')
