# 45분 알람 일찍 설정하기

# [sol1]
# H M 하루 1440분(60 * 24)
# 60 * H + M - 45 = 100 (= t)
# H -> 100 / 60
# M -> 100 % 60
# if 60 * H + M - 45 < 0 then 1440 + t
# H -> (1440 + t) / 60
# M -> (1440 + t) % 60

# H, M = map(int, input().split())
# t = 60 * H + M - 45
# if t >= 0 :
#     print(int(t / 60), int(t % 60), sep=' ')
# else : 
#     print(int((1440 + t) / 60), int((1440 + t) % 60), sep = ' ')
    
# [sol2]
# if M > 44 then M - 45
# elif M < 45 and H > 0 then H = H - 1 , M = M + 15
# else H = 23, M = M + 15 

H, M = map(int, input().split())
if M > 44 :
    print(H, M - 45)
elif M < 45 and H > 0 :
    print(H - 1, M + 15)
else :
    print(23, M + 15)
