N = int(input())

word = {}
for i in range(N):
    str = input()
    if len(str) in word:
        word[len(str)].append(str)
    else:
        word[len(str)] = [str]

for i in word:
    word[i].sort()

tmp = []
for i in word:
    tmp.append(i)
    tmp.sort()
    
jb = []
for i in range(len(tmp)):
    for j in range(len(word[tmp[i]])):
        if word[tmp[i]][j] not in jb:
            print(word[tmp[i]][j])
        jb.append(word[tmp[i]][j])