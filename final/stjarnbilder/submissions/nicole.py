#!/usr/bin/env python3
N = int(input())

first = []
second = []
for _ in range(N):
    a,b = map(int, input().split())
    first.append([a,b])
for _ in range(N):
    a,b = map(int, input().split())
    second.append([a,b])

freq = {}
for i in range(N):
    for j in range(N):
        diff = (first[i][0]-second[j][0], first[i][1]-second[j][1])
        if diff not in freq:
            freq[diff] = 0
        freq[diff] += 1
ans = 0
for val in freq.values():
    ans = max(ans, val)

print(N-ans)
