# 실버3
# 피보나치
# '''
def fibonacci(n):
    ans0, ans1 = [0]*41, [0]*41
    ans0[0], ans1[1] = 1, 1
    
    for i in range(2, n+1):
        ans0[i] = ans0[i-1] + ans0[i-2]
        ans1[i] = ans1[i-1] + ans1[i-2]
    print(ans0[n], ans1[n])


T = int(input())
for _ in range(T):
    n = int(input())
    fibonacci(n)
    
# '''

# '''
def fibonacciDP(n):
    ans = [0]*100
    ans[0] = 0
    ans[1] = 1
    for i in range(2, n+1):
        ans[i] = ans[i-1] + ans[i-2]
    return ans[n]


global countZero
global countOne
countZero = 0
countOne = 0
def fibonacci(n):
    global countZero
    global countOne
    if n == 0:
        countZero+=1
        return 0
    elif n == 1:
        countOne+=1
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

# print(fibonacciDP(40))
# fibonacci(35)
# print(countZero, countOne)
# '''

