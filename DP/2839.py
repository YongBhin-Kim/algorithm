# 실버4
# 설탕 배달
# 3kg, 5kg 봉지 -> Nkg 배달

# 17 -> 14 + 3
# 18 -> 5 5 5 3
# 9 -> 3 3 3
# 11 -> 5 3 3

N = int(input())
bag = 0
while N >= 0 :
    if N % 5 == 0 :  # 5의 배수이면
        bag += (N // 5)  # 5로 나눈 몫을 구해야 정수가 됨
        print("5 call")
        print(bag)
        break
    N -= 3  
    bag += 1  # 5의 배수가 될 때까지 설탕-3, 봉지+1
    print("3 call")
else :
    print(-1)


# 18 = 5a + 3b
