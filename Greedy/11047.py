N, K = map(int, input().split())

list = []
for i in range(N):
    list.append(int(input()))

count = 0

for i in range(N-1, -1, -1): # 4, 0, -1 # N-1 ~ 0 , -1방향
    # if list[i] > K:
        # continue
    if list[i] <= K:
        count += K // list[i] # 몫
        K = K % list[i] # 나머지
        
    
print(count)
