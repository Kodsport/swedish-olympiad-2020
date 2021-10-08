import sys, random

def cmdlinearg(name):
	for arg in sys.argv:
		if arg.startswith(name + "="):
			return arg.split("=")[1]

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n"))
m = int(cmdlinearg("m"))

print(n, m, 1)
for i in range(n):
	print(random.randint(1, 99), random.randint(500, m), 100)
