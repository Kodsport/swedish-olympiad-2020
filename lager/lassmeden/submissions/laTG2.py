def que(x):
    if soll[x]: print 'Ja'
    else: print 'Nej'

def add(a,b):
    for x in range(a,N,b):
        soll[x] = True

#Not included in this group.
def rem(a,b):
    pass

N,Q = map(int,raw_input().split())
soll = [False]*(N+1)
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
