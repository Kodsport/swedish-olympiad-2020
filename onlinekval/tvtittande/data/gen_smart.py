#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed = int(cmdlinearg('seed', sys.argv[-1]))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))
ans = cmdlinearg('ans')
days = int(cmdlinearg('days'))
maxcsum = int(cmdlinearg('maxcsum', 200000))
f = float(cmdlinearg('f', 0.1))
concentrate = int(cmdlinearg('concentrate', 0))
assert 0 <= f <= 1
assert concentrate == 0 or concentrate == 1
assert n <= days
assert maxcsum >= n
assert ans == 'Ja' or ans == 'Nej'
assert k <= (days+1-n)*10
assert not (n == 1 and k == 1 and days == 100000 and ans == 'Nej')

random.seed(seed)

events = random.sample(range(1, days+1), k=n)
events.sort()
events[-1] = days

usehours = [0]*n
usehours[0] = 1
mustuse = []
if(n+k-maxcsum-1 > 0): #om nya filmer diskuteras på för få kalas kommer maxcsum inte räcka för att inget kalas ska vara utan diskussion.
    mustuse = random.sample(range(1, n), k=(n+k-maxcsum-1))
for i in mustuse: usehours[i] = 1
for i in range(k-1-len(mustuse)):
    p = random.randint(0, n-1)
    usehours[p] = 1

hours = 0
prevday = -1
for i in range(n):
    while(events[i] <= prevday): events[i]+=1
    hours += 10*(events[i]-prevday-1)
    hours -= usehours[i]
    if(hours < 0):
        events[i] += 1
        hours += 10
    prevday = events[i]
assert events[-1] == days

rem = 0
hours = 0
prevday = -1
for i in range(n):
    if(usehours[i] == 0):
        hours -= 10
        continue
    hours += 10*(events[i]-prevday-1)
    usehours[i] = random.randint(0, min(hours, 10*(events[i]-prevday-1)+10))
    if(hours >= 4 and (random.uniform(0,1)<f or i == n-1)):
        if(random.uniform(0,1)<0.5):
            usehours[i] = random.randint(0, hours)
        else:
            usehours[i] = hours-random.randint(0,2)
    if(i == 0 and usehours[i] == 0): usehours[i]=1
    if(usehours[i] == 0):
        usehours[i] = 1
        if(hours == 0):
            hours += 1
            rem += 1
    hours -= usehours[i]
    prevday = events[i]
for i in range(n):
    while(usehours[i] > 1 and rem > 0):
        rem -= 1
        usehours[i] -= 1
assert rem == 0

if(ans == 'Nej'):
    prevday = -1
    hours = 0
    failday = random.randint(0, n-1)
    while(usehours[failday] == 0): failday = random.randint(0, n-1)
    for i in range(n):
        hours += 10*(events[i]-prevday-1)
        prevday = events[i]
        if(i == failday):
            usehours[i] = hours + random.randint(1, 2)
        hours -= usehours[i]

nonzero = []
for i in range(n):
    if(usehours[i] != 0): nonzero.append(i)

d = [0]*n #nya tv-serier
t = 0
for i in range(n):
    if(usehours[i] != 0):
        d[i] = 1
        t+=1
if concentrate == 0:
    for i in range(k-t):
        p = random.randint(0,len(nonzero)-1)
        d[nonzero[p]] += 1
else:
    p = -1
    pl = -1
    for i in nonzero:
        if(usehours[i] > pl):
            pl = usehours[i]
            p = i
    d[p] += k-t

extra = 0
for i in range(n):
    if(usehours[i] == 0):
        continue
    d[i] += extra
    extra = 0
    if(d[i] > usehours[i]):
        extra = d[i]-usehours[i]
        d[i] = usehours[i]
d[-1] += extra
usehours[-1] += extra

r = [0]*n #gamla tv-serier
s = k
for i in range(n):
    if(d[i] == 0):
        r[i] = 1
        s += 1
for i in range(maxcsum-s):
    p = random.randint(0,n-1)
    r[p] += 1
csum = maxcsum
o = 0
for i in range(n):
    if(r[i] > o):
        csum -= r[i]-o
        r[i] = o
    o += d[i]
o = 0
for i in range(n):
    while(r[i] < o and csum < maxcsum):
        r[i] += 1
        csum += 1
    o += d[i]

lengths = []
serier = []
for i in range(n):
    assert d[i] <= usehours[i]
    a = [1]*d[i]
    for j in range(usehours[i]-d[i]):
        p = random.randint(0, len(a)-1)
        a[p]+=1
    serier.append([])
    serier[-1].extend(random.sample(range(1, len(lengths)+1), k=r[i]))
    for j in range(d[i]):
        serier[-1].append(len(lengths)+j+1)
    lengths.extend(a)

p = list(range(len(lengths)))
random.shuffle(p)
inv = [0]*len(p)
for i in range(len(inv)): inv[p[i]] = i
lengths = [lengths[p[i]] for i in range(len(lengths))]

assert csum == sum(d)+sum(r)

print(n, len(lengths))
print(*lengths)
for i in range(n):
    random.shuffle(serier[i])
    serier[i] = [inv[j-1]+1 for j in serier[i]]
    print(events[i], len(serier[i]), *serier[i])
