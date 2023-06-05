## =========================================
## 22년 5월 국민대 코딩역량
## 알람시계
## =========================================

h, m = map(int, input().split())
target = (h * 60 + m - 10) % 1440 # 분으로 전부 바꿈 # 24 00 == 00 00 이므로 mod 1440
presets = []

for _ in range(5):
    h, m = map(int, input().split())
    presets.append(h * 60 + m)

# target = 0 --> 0
# target = 10 --> 10
# target = -10 == 1430 --> 10
nopreset_cnt = min(abs(target), abs( (-target) % 1440))

pmin = min( min(abs(target - p) % 1440, abs(target - p) + 1 ) for p in presets)

print(min(pmin, nopreset_cnt))