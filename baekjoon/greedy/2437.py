# 백준 2437. 저울(골2) 23.07.03

N = int(input())
weight = list(map(int, input().split()))
weight.sort()

res = 1
for i in weight:
    if i > res: 
        break
    res+=i
print(res)
