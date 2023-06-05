# 정수 삼각형

n = int(input())
ans = []
dp = [[] for _ in range(n)]
ans.append(list(map(int, input().split())))
dp[0].append(ans[0][0])

for i in range(1,n):
    ans.append(list(map(int, input().split())))
    
    dp[i].append(ans[i][0]+dp[i-1][0])
    for j in range(1, i):
        dp[i].append(ans[i][j] + max(dp[i-1][j], dp[i-1][j-1]))
    dp[i].append(ans[i][i]+dp[i-1][i-1])
    
print(max(dp[n-1]))