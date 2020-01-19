import sys, random

def cmdlinearg(name, default):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert(default != None)
    return default

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n", None))
m = int(cmdlinearg("m", 10**9))

print(n)
points = set()
x = random.randint(1,m)
y = random.randint(1,m/2)
dx = [1,0,-1,0]
dy = [0,1,0,-1]

lox = 1
hix = x-1
loy = y+1
hiy = m
cx = x
cy = y
ctp = 2

s1 = []
for i in range(n//5):
    mx = random.randint((hix-lox)//2,hix-lox)
    my = random.randint((hiy-loy)//2,hiy-loy)
    cx = cx+dx[ctp]*mx
    cy = cy+dy[ctp]*my
    if ((cx < lox or cx > hix) and dx[ctp] != 0):
        break
    if ((cy < loy or cy > hiy) and dy[ctp] != 0):
        break
    if (ctp == 0):
        hix = cx-1
    elif (ctp == 1):
        hiy = cy-1
    elif (ctp == 2):
        lox = cx+1
    elif (ctp == 3):
        loy = cy+1
    s1.append((cx,cy))
    ctp = (ctp+3)%4


lox = x+1
hix = m
loy = y+1
hiy = m
cx = x
cy = y
ctp = 0

s2 = []
for i in range(n//5):
    mx = random.randint((hix-lox)//2,hix-lox)
    my = random.randint((hiy-loy)//2,hiy-loy)
    cx = cx+dx[ctp]*mx
    cy = cy+dy[ctp]*my
    if ((cx < lox or cx > hix) and dx[ctp] != 0):
        break
    if ((cy < loy or cy > hiy) and dy[ctp] != 0):
        break
    if (ctp == 0):
        hix = cx-1
    elif (ctp == 1):
        hiy = cy-1
    elif (ctp == 2):
        lox = cx+1
    elif (ctp == 3):
        loy = cy+1
    s2.append((cx,cy))
    ctp = (ctp+1)%4

for s in s1:
    points.add(s)
for s in s2:
    points.add(s)


while len(points) < n - n//10:
    if (random.randint(1,2) == 1):
        k = random.randint(0,len(s1)-2)
        if (s1[k][0] == s1[k+1][0]):
            points.add((s1[k][0],random.randint(min(s1[k][1],s1[k+1][1]), max(s1[k][1],s1[k+1][1]))))
        elif (s1[k][1] == s1[k+1][1]):
            points.add((random.randint(min(s1[k][0],s1[k+1][0]), max(s1[k][0],s1[k+1][0])), s1[k][1]))
    else:
        k = random.randint(0,len(s2)-2)
        if (s2[k][0] == s2[k+1][0]):
            points.add((s2[k][0],random.randint(min(s2[k][1],s2[k+1][1]), max(s2[k][1],s2[k+1][1]))))
        elif (s2[k][1] == s2[k+1][1]):
            points.add((random.randint(min(s2[k][0],s2[k+1][0]), max(s2[k][0],s2[k+1][0])), s2[k][1]))

while len(points) < n:
    points.add((random.randint(1,m),random.randint(1,m)))

ps = []
for p in points:
    ps.append(p)
random.shuffle(ps)
for p in ps:
    print(p[0],p[1])
