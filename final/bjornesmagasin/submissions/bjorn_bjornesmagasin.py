def parse():
    month_to_days = [31,28,31,30,31,30,31,31,30,31,30,31]

    d,m = map(int, raw_input().split("/"))
    return d-1 + sum(month_to_days[:m-1]) #dag, nollindexerad


N, D = map(int,raw_input().split())
bjorne = parse()
bears = [(parse()-bjorne)%365 for i in range(N-1)] #Anta att bjorne sover [0,d-1]
bears = list(set(bears))
bears = map(lambda b: (b+D)%365, bears) #Remappa sa att bears ar nar bjornar vaknar
bears.sort()

if D==0:
    print 0
    exit()

if N==1:
    print -1
    exit()
state = 0
used = 0
if bears[0] == 0:
    state = 365-D
    used+=1
else:
    st = bears[-1]
    en = st-D
    if en<=0:
        print -1
        exit()
    state = en
    used +=1
while bears and state < D:
    while len(bears)>1 and bears[1] <= state:
        bears.remove(bears[0])
    st = bears[0]
    en = st+365-D
    if st>state:
        print -1
        exit()
    state = en
    used +=1
    bears.remove(bears[0])
if state<D:
    print -1
    exit()
print used
