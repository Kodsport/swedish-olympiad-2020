from collections import defaultdict 

def que(x):
    suc = soll[x] > 0
    for m in range(1,thres+1):
        if good[m][x%m] > 0: 
            suc = True
            break
    if suc: print('Ja')
    else: print('Nej')

def add(a,b):
    if b <= thres:
        good[b][a] += 1
    else:
        for x in range(a,N+1,b):
            soll[x] += 1

def rem(a,b):
    if b <= thres:
        good[b][a] -= 1
    else:
        for x in range(a,N+1,b):
            soll[x] -= 1

thres = 350
N,Q = map(int,input().split())
good = [[0]*x for x in range(thres+1)]
soll = [0]*(N+1)
for _ in range(Q):
    s = input()
    if s[0] == '1':
        _,x = map(int,s.split())
        que(x)
    elif s[0] == '2':
        _,a,b = map(int,s.split())
        add(a,b)
    elif s[0] == '3':
        _,a,b = map(int,s.split())
        rem(a,b)
