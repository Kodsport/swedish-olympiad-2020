n = int(raw_input())

pts1, pts2 = [], []
for i in range(n):
	pts1.append(tuple(map(int, raw_input().split())))
for i in range(n):
	pts2.append(tuple(map(int, raw_input().split())))

pts1.sort()
pts2.sort()
pts2Set = set(pts2)

maxSt = 0
for i in range(n):
	dx = pts2[i][0] - pts1[i][0]
	dy = pts2[i][1] - pts1[i][1]
	numSt = 0
	for c in pts1:
		if (c[0] + dx, c[1] + dy) in pts2Set:
			numSt += 1
	maxSt = max(maxSt, numSt)
print(n - maxSt)
