# produces 90% impossible, 10% multiple solutions with no strong hamming weight biases
# not a very good generator, honestly
n = 2*10**5
q = 2*10**5
k = 21

print(n, k)
for i in range(n):
    print(bin(i)[2:][::-1].ljust(k, '0'))

print(q)
for i in range(q):
    print(bin(i)[2:].rjust(k, '0'))
