# 연속합

# 2 1 -4 3 4 -4 6 5 -5 1
# 2 3 -1/3 7  3 9 14 9 10
# max(dp)

n = int(input())
num = list(map(int, input().split()))
dp = [0]*n
dp[0]=num[0]

for i in range(1,n):
    dp[i] = max(dp[i-1]+num[i], num[i])
print(max(dp))