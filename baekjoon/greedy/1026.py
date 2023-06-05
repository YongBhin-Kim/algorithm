
N = int(input())

A = list(map(int, input().split())) 
B = list(map(int, input().split())) 


## Sol 1 : sort 이용
# A.sort()        
# B.sort(reverse=True)

outNum = 0
# for i in range(N):
#     outNum += A[i] * B[i]

A.sort()
for i in range(N):
    outNum += A[i] * max(B)
    B.pop(B.index(max(B)))

print(outNum)