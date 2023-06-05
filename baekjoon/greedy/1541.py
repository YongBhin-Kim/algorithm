# 잃어버린 괄호
# numList[0]은 다 +
# numList[1]부터 다 -

minList = input().split('-')
firstsum = sum(map(int, minList.pop(0).split('+')))
restSum = 0
for i in range(len(minList)):
    restSum -= sum(map(int, minList[i].split('+')))
print(firstsum + restSum)