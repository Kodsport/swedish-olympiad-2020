from heapq import *
N, M = map(int, input().split(" "))
queue = list(range(M))
for turns in map(int, input().split(" ")):
	heappush(queue, heappop(queue) + turns * M)
print(max(queue))
