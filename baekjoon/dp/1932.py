# 정수 삼각형

n = int(input())
tree = []
dp = [[] for _ in range(n)]
tree.append(list(map(int, input().split())))
dp[0].append(tree[0][0])

for i in range(1,n):
    tree.append(list(map(int, input().split())))
    
    dp[i].append(tree[i][0]+dp[i-1][0])
    for j in range(1, i):
        dp[i].append(tree[i][j] + max(dp[i-1][j], dp[i-1][j-1]))
    dp[i].append(tree[i][i]+dp[i-1][i-1])
    
print(max(dp[n-1]))

for i in range(n):
    for j in range(len(dp[i])):
        print(dp[i][j], end=" ")
    print()