# 1로 만들기(silver3)

N = int(input())

ans = [0]*(N+1) #ans[0]=0 ans[1]=0 ans[2]=1

for i in range(2, N+1):
    ans[i] = 1 + min(ans[i//3] + i%3, ans[i//2] + i%2)
    print("ans[%s]= "%i, ans[i])
    
print(ans[N])
    
# 11 -> 1+ans[3]+2  vs  1+ans[5]+1
# 10 -> 1+ans[3]+1  vs  1+ans[5]+0
