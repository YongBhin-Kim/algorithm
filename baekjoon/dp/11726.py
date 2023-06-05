# 2*n 타일링
# dp[n] = dp[n-2] = dp[n-1]

n = int(input())
dp = [0]*1001
dp[1] = 1; dp[2] = 2
for i in range(3,n+1):
    dp[i] = (dp[i-2] + dp[i-1])%10007
    
print(dp[n])