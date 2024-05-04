n, m = map(int, input().split())
mlist = list(map(int, input().split()))
clist = list(map(int, input().split()))

inf = sum(clist)
dp = [-1] * (inf+1)
dp[0] = 0

max_cost = 0
found = False
for i in range(n) :
    for j in range(max_cost, -1, -1) :
        if dp[j] != -1 :
            dp[j + clist[i]] = max(dp[j + clist[i]], dp[j] + mlist[i])
            
            if not found :
                max_cost = max(max_cost, j + clist[i])
                
            if dp[j + clist[i]] >= m :
                found = True
                max_cost = min(max_cost, j + clist[i])
                
                
print(max_cost)