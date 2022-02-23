# 사분면 (1~4) 출력
# x, y를 받아서

x = int(input())
y = int(input())

if x > 0 :
    if y > 0 : print(1)
    elif y < 0 : print(4)
else :
    if y > 0 : print(2)
    elif y < 0 : print(3)