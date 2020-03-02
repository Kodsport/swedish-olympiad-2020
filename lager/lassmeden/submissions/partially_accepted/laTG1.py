from collections import defaultdict
def que(x):
    for m in range(1,N+1):
        if good[m][x%m] > 0:
            print 'Ja'
            return
    print 'Nej'

def add(a,b):
    good[b][a] += 1

def rem(a,b):
    good[b][a] -= 1

N,Q = map(int,raw_input().split())
good = [defaultdict(int) for _ in range(N+1)]
for _ in range(Q):
    s = raw_input()
    if s[0] == '1':
        _,x = map(int,s.split())
        que(x)
    elif s[0] == '2':
        _,a,b = map(int,s.split())
        add(a,b)
    elif s[0] == '3':
        _,a,b = map(int,s.split())
        rem(a,b)
