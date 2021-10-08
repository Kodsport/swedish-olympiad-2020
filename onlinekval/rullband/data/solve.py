from heapq import *

def solve(n,m,g,band,onlyForward=False):
    e = [[] for _ in range(m)]
    for b in band:
        e[b[0]].append([b[1],b[2]])
    
    if onlyForward:
        dp = [1e18]*m
        dp[m-1] = 0
        for i in range(m-2,-1,-1):
            dp[i] = dp[i+1]+g
            for u,d in e[i]:
                dp[i] = min(dp[u]+d,dp[i])
        return dp[0]+g
    else:
        seen = [False]*m
        q = []
        heappush(q, (0,0))
        while len(q):
            dist,v = heappop(q)
            if v<0 or v>=m or seen[v]:
                continue
            if v==m-1:
                return dist+g
            seen[v] = True
            heappush(q,(dist+g,v-1))
            heappush(q,(dist+g,v+1))
            for u,d in e[v]:
                heappush(q,(dist+d,u))
    assert(False)

        