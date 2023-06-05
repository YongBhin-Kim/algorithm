# # 계단 오르기

# # dp = [0 10 20 15 25 10 20]
# # 10 -> 20 -> 25 -> 20

# # dp[n] = num[n-1]+dp[n-3] vs dp[n-2]

num = [0]

n=int(input())
for _ in range(n):
    num.append(int(input()))
dp=[0]*(n+1)
dp[1]=num[1]
dp[2]=num[1]+num[2]
for i in range(3,n+1):
    dp[i]= num[i] + max(num[i-1]+dp[i-3], dp[i-2])
        
print(dp[n])