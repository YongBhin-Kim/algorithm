p, l = map(int, input().split())

numList = input().split()

outList = [int(numList[i]) - p*l for i in range(5)]

for i in outList:
    print(i)