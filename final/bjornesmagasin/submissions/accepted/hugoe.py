#!/usr/bin/env python3
#full solution
n,d = input().split()
n = int(n)
d = int(d)

mth = [0,31,28,31,30,31,30,31,31,30,31,30,31]

def day(mm,dd):
    cnt = 0
    for i in range(mm):
        cnt += mth[i]
    cnt += dd-1
    return cnt

days = [0]*365

for i in range(n):
    dd,mm = input().split("/")
    mm = int(mm)
    dd = int(dd)
    if (i == 0):
        bj = (day(mm,dd)+d)%365
    else:
        days[(day(mm,dd)+d)%365] = 1

lst = bj
cnt = 365-d
ans = 0

while cnt < 365:
    for i in range(365-d,0,-1):
        if (days[(lst+i)%365]):
            cnt += i
            ans += 1
            lst = (lst+i)%365
            break
        if i == 1:
            print(-1)
            exit(0)
print(ans)
