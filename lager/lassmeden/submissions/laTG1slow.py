def que(x):
    for a,b in keys:
        if (x-a) % b == 0:
            print 'Ja'
            return
    print 'Nej'

def add(a,b):
    keys.append((a,b))

def rem(a,b):
    keys.remove((a,b))

N,Q = map(int,raw_input().split())
keys = []
for q in range(Q):
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
