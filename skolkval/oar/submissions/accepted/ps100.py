import sys
N=int(sys.stdin.readline())
i=0
j=1
n=0
while N>0:
	n+=1
	k=i
	i+=j
	j=k
	N-=i
print n

