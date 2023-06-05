# 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 
# 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

# 예제 입력 1 
# 100
# 예제 출력 1 
# A

num = int(input())
if num>=90:
    print('A')
elif num >= 80:
    print('B')
elif num >=70:
    print('C')
elif num>=60 :
    print('D')
else:
    print('F')
    