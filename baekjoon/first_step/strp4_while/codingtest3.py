# 여기부터

num = int(input())
count = 0
tmpA = num

while True:
    # 26 = 2 + 6 = 68
    tmpB = (tmpA%10)*10 + (tmpA/10 + tmpA%10)
    count += 1
    
    if tmpB == num:
        print(count)
        break
        
