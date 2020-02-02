import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

def random_plain(): #'plain'
    return random.randint(1,N)

def random_half_below_sqrtN(): #'_half_below_sqrtN'
    if random.randint(1,2) == 1: return random.randint(1,int(N**0.5))
    return random.randint(int(N**0.5)+1,N)

def random_95percent_below_sqrtN(val=20): #'_95percent_below_sqrtN'
    if random.randint(1,val) == 1: return random.randint(int(N**0.5)+1,N)
    return random.randint(1,int(N**0.5))

def random_95percent_below_sqrtsqrtN(val=20): #'_95percent_below_sqrtsqrtN'
    if random.randint(1,val) == 1: return random.randint(int(N**0.25)+1,N)
    return random.randint(1,int(N**0.25))

def random_95percent_below_smallersqrtsqrtN(val=20): #'_95percent_below_sqrtsqrtN'
    if random.randint(1,val) == 1: return random.randint(int(N**0.25)+1,N)
    return random.randint(1,int(N**0.25*0.4))

def random_different_Bs():
    x = random.randint(0,len(unusedB)-1)
    b = unusedB[x]
    unusedB[x] = unusedB[-1]
    unusedB.pop()
    return b

def random_95percent_above_NsqrtN():
    if random.randint(1,20) == 1: return random.randint(N-int(N**0.5),N)
    return random.randint(1,N)

def largest_possible():
    return unusedB.pop()

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
N = int(cmdlinearg('N'))
Q = int(cmdlinearg('Q'))
different_Bs = int(cmdlinearg('different_Bs',0))
q1 = int(cmdlinearg('q1'))
q2 = int(cmdlinearg('q2'))
q3 = int(cmdlinearg('q3'))
random_choice = cmdlinearg('randMethod','plain') #Can be according to above.
assert Q == q1+q2+q3, 'Sum of query types wrong'
assert q3 <= q2, 'More removed than added keys'
assert not different_Bs or q2 <= N, 'Too small N in different_Bs case'
unusedB = list(range(1,N+1))

keys = []

print(N,Q)
while q1+q2+q3:
    x = random.randint(1,q1+q2+q3)
    if x <= q1: 
        op = 1
        q1 -= 1
    elif x <= q1+q2 or not keys: 
        op = 2
        q2 -= 1
    else: 
        op = 3
        q3 -= 1
    if op == 1: print(1,random.randint(1,N))
    elif op == 2:
        if different_Bs: b = random_different_Bs()
        elif random_choice == 'plain': b = random_plain()
        elif random_choice == '_half_below_sqrtN': b = random_half_below_sqrtN()
        elif random_choice == '_95percent_below_sqrtN': b = random_95percent_below_sqrtN()
        elif random_choice == '_95percent_below_sqrtsqrtN': b = random_95percent_below_sqrtsqrtN()
        elif random_choice == '_95percent_below_smallersqrtsqrtN': b = random_95percent_below_smallersqrtsqrtN()
        elif random_choice == '_95percent_above_NsqrtN': b = random_95percent_above_NsqrtN()
        elif random_choice == '_only_largest': b = largest_possible()
        a = random.randint(0,b-1)
        print(2,a,b)
        keys.append((a,b))
    else:
        x = random.randint(0,len(keys) - 1)
        k = keys[x]
        print(3,k[0],k[1])
        keys[x] = keys[-1]
        keys.pop()
