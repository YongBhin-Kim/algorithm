# 피보나치

def fibo(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return fibo(n-1) + fibo(n-2)

n = int(input())
def fibo_dp(n):
    ans = [0]*(n+1)
    ans[1] = 1
    for i in range(2,n+1):
        ans[i] = ans[i-1] + ans[i-2]
    return ans[n]
print(fibo_dp(n))
