n = int(input())

pts1, pts2 = [], []
for i in range(n):
	pts1.append(tuple(map(int, input().split())))
for i in range(n):
	pts2.append(tuple(map(int, input().split())))

pts2Set = set(pts2)

maxStars = 0
for a in pts1:
	for b in pts2:
		dx = b[0] - a[0]
		dy = b[1] - a[1]
		st = 0
		for c in pts1:
			if (c[0] + dx, c[1] + dy) in pts2Set:
				st += 1
		maxStars = max(maxStars, st)

print(n - maxStars)
