# 가장 긴 증가하는 부분 수열

# 10 20 1 2 3 4 5 6 7 8 30 50


n = int(input())
num = input().split()
for i in range(len(num)):
    num[i] = int(num[i])

dp = [0]*(n)

for i in range(n):
    for j in range(i):
        if num[i]>num[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i]+=1
        
print(max(dp))