#sample 1 fel, ska va vet ej

n,k = map(int, raw_input().split())
bin_to_set = {}
for i in range(2**k):
    bin_to_set[i] = set()
for i in range(n):
    s = raw_input()
    n = 0
    for ch in s:
        n*=2
        if ch=='1':
            n+=1
    bin_to_set[n].add(i)
for i in range(2**k-1,-1,-1):
    if len(bin_to_set[i])>2:
        bin_to_set[i]=set(list(bin_to_set[i])[:2]) #undvik stora listor

    n = i
    for j in range(k):
        if n%2==1:
            for el in bin_to_set[i]:
                bin_to_set[i-2**j].add(el)
        n/=2
q = input()
for i in range(q):
    s = raw_input()
    n = 0
    for ch in s:
        n*=2
        if ch=='1':
            n+=1
    if len(bin_to_set[n]) == 0:
        print "finns ej"
    elif len(bin_to_set[n]) == 1:
        print list(bin_to_set[n])[0]+1
    else:
        print "vet ej"
