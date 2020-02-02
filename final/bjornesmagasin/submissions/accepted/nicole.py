#!/usr/bin/env python3
n,d = map(int, input().split())

days = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
if d==0:
    print(0)
    exit()

def get_day_from_date(s):
    day = int(s[0])*10+int(s[1])
    month = int(s[3])*10+int(s[4])
    for i in range(1,month):
        day += days[i]
    return day


bjorne = get_day_from_date(input())
bears_awake = []
for _ in range(n-1):
    s = input()
    day = get_day_from_date(s)-bjorne
    awakes = (day+d-1)%365
    bears_awake.append(awakes)

bears_awake.sort()
for i in range(len(bears_awake)):
    bears_awake[i] += 1
start = 0 # från och med denna är det inte lugnt
end = start+d # från och med denna är det lugnt

if bears_awake[-1]+365-d >= 365:
    bears_to_use = [bears_awake[-1]-365]

else:
    print(-1)
    exit()

for i in range(n-2):
    if bears_awake[i] < end:
            bears_to_use.append(bears_awake[i])

# Vill bara ha den som är precis innan samt björnar som vaknar under dvalan
ans = 0
new_start = start
for i in range(len(bears_to_use)):
    if start >= end:
        print(ans)
        exit()
    awake = bears_to_use[i]
    asleep = awake + (365-d)
    if awake > start:
        start = new_start
        ans += 1
    if awake <= start:
        new_start = asleep

if new_start!= start and start < end:
    start = new_start
    ans+=1

if start >= end:
    print(ans)

else:
    print(-1)
