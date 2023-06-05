# 1002 : 터렛
from cmath import sqrt
T = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    if x1 == x2 and y1 == y2:
        if r1 == r2:
            print(-1)
        else:
            print(0)
        continue
    
    d = ((x2-x1)**2 + (y2-y1)**2)**0.5
    if min(r1,r2) == abs(max(r1,r2) - d):
        print(1)
    elif min(r1,r2) > abs(max(r1,r2) - d):
        print(2)
    else:
        print(0)