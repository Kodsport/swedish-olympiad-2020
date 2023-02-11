n = int(input())

pts1, pts2 = [], []
for i in range(n):
	pts1.append(tuple(map(int, input().split())))
for i in range(n):
	pts2.append(tuple(map(int, input().split())))

minX1, minY1 = pts1[0]
minX2, minY2 = pts2[0]
for i in range(1, n):
	minX1 = min(minX1, pts1[i][0])
	minY1 = min(minY1, pts1[i][1])
	minX2 = min(minX2, pts2[i][0])
	minY2 = min(minY2, pts2[i][1])

for i in range(n):
	pts1[i] = (pts1[i][0] - minX1, pts1[i][1] - minY1)
	pts2[i] = (pts2[i][0] - minX2, pts2[i][1] - minY2)

pts1.sort()
pts2.sort()
print(int(pts1 != pts2))
