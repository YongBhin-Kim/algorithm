# 첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)


N = int(input())
list = list(map(int, input().split()))
list.sort()
sum = 0 
for i in range(N):
    sum += list[i] * (N - i)
    
print(sum)