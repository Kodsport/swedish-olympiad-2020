from heapq import *
N, M = map(int, raw_input().split(" "))
queue = list(range(M))
for turns in map(int, raw_input().split(" ")):
	heappush(queue, heappop(queue) + turns * M)
print(max(queue))
