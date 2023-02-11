n = int(input())

pts1, pts2 = [], []
for i in range(n):
	pts1.append(tuple(map(int, input().split())))
for i in range(n):
	pts2.append(tuple(map(int, input().split())))

freq = { }
maxStars = 0
for a in pts1:
	for b in pts2:
		delta = (a[0] - b[0], a[1] - b[1])
		if not delta in freq:
			freq[delta] = 1
		else:
			freq[delta] += 1
		maxStars = max(maxStars, freq[delta])

print(n - maxStars)
