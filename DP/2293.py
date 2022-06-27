# 동전 1

# 6을 만드는 경우의수 = 5를 만드는 경우의 수 + 4를 만드는 경우의 수 + 1을 만드는 경우의 수
# 7을 만드는 경우의수 = 6를 만드는 경우의 수 + 5를 만드는 경우의 수 + 2을 만드는 경우의 수
# .
# .
# .
# 10을 만드는 경우의수 = 9를 만드는 경우의 수 + 8을 만드는 경우의 수 + 5를 만드는 경우의 수

# dp[0] dp[1] dp[2] dp[3] dp[4]   dp[5]       dp[6]     dp[7]
#         1    11   111   1111    11111      111111     1111111

#              2    2 1   2 11    2 111      2 1111     2 11111
#                         2 2     2 21       2 211      2 2111
#                                            2 22       2 221 -> dp[7] + dp[5]

#                                 5          5 1        5 11
#                                                       5 2 -> dp[7] + dp[2]
# dp[7] += dp[7-i]

n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)]
dp = [0]*(k+1)
dp[0] = 1

for i in coin: # 1 2 5원 사용
    for j in range(i, k+1): # 1원 사용 # 2원 사용
        dp[j] += dp[j-i]
print(dp[k])



## 처음 동전의 경우(전부 한가지로 select)는 경우의수 1로 미리 할당
'''
n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)]
dp = [1]*(k+1)

for i in range(1,len(coin)): # 1 2 5원 사용
    for j in range(coin[i], k+1): # 1원 사용 # 2원 사용
        dp[j] += dp[j-coin[i]]
print(dp[k])
'''