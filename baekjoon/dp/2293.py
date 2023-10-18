# 백준 동전 1 (골5)

# 1 1 1 1 1 1 1 1 1 1 1
#     1   
#       1 2
#           2 3
#               3 4
#                   4 5
#           1
#             1 2
#                 2 3
#                     4
# 1 1 2 2 3 4 5 6 7 8 10

# dp[4] += dp[4-2] # coin=2
# dp[5] += dp[5-5] # coin=5
# dp[i] += dp[i-coin]

n, k = map(int, input().split()) # 10
coin = [int(input()) for _ in range(n)] # 1 2 5
dp = [0]*(k+1)
dp[0] = 1

for w_coin in coin: 
    for j in range(w_coin, k+1): 
        dp[j] += dp[j-w_coin]
print(dp)
