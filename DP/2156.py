# 포도주 시식
# 6 10 13 9  8 1
# 6 10 90 9  8 1

# 6 16 96 19 (dp[i-1])
# 6 16 19 28 (num[i]+dp[i-2])
# 6 16 19 25 (num[i]+num[i-1]+dp[i-3])

n = int(input())
num=[0]*10000
for i in range(n):
    num[i]=int(input())
dp=[0]*10000

dp[0]=num[0]
dp[1]=num[0]+num[1]
dp[2]=max(dp[1], num[2]+num[1], num[2]+num[0])
for i in range(3,n):
    dp[i]=max(dp[i-1], num[i]+dp[i-2], num[i-1]+num[i]+dp[i-3])
    
print(num)
print(dp[n-1])

