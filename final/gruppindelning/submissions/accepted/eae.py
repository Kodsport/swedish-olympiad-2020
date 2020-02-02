#!/bin/python2
n, m = map(int, raw_input().split())
nPairs = (n + 1) // 2

edges = [[] for i in range(nPairs)]
for i in range(m):
	a, b = map(lambda s: int(s) - 1, raw_input().split())
	same = b % 2 == a % 2
	edges[a // 2].append((b // 2, same))
	edges[b // 2].append((a // 2, same))

color = [-1] * nPairs
for i in range(nPairs):
	if color[i] != -1:
		continue
	stack = [i]
	color[i] = 0
	while stack:
		cur = stack.pop()
		for nx, same in edges[cur]:
			nextC = color[cur] if same else 1 - color[cur]
			if color[nx] == -1:
				color[nx] = nextC
				stack.append(nx)
			elif color[nx] != nextC:
				print(-1)
				exit(0)

ans = "".join(map(lambda c: ["12", "21"][c], color))
print(ans[:n])
