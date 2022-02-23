# 빠른 A + B

import sys

count = int(input())
for _ in range(count):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    print(a + b)