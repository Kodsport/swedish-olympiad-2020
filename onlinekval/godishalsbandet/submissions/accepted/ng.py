s = input()
n = len(s)
ans = 0
blue = 0
for i in range(0,n//2):
    blue += (s[i] == 'B')

for i in range(0,n):
    ans = max(ans, blue)
    blue -= (s[i] == 'B')
    j = (i + n//2)%n
    blue += (s[j] == 'B')

print(ans)
