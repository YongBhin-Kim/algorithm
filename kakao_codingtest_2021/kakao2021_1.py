upAlphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
step2 = '~!@#$%^&*()=+[{]}:?,<>/'
num = '0123456789'
def solution(new_id):
    answer = ''
    ## step 1
    item = [new_id.lower()[i] for i in range(len(new_id))]

    ## step 2
    i = 0; lenItem = len(item)
    while True:
        if i == lenItem:
            break
        if item[i] in step2:
            del item[i]
            i -= 1
            lenItem -= 1
        i += 1

    ## step 3
    i = 1; lenItem = len(item)
    while True:
        if i == lenItem:
            break
        if item[i-1] == '.':
            if item[i] == '.':
                del item[i]
                i -= 1
                lenItem -= 1
        i += 1

    ## step 4
    if item[0] == '.':
        del item[0]
    if len(item) != 0:
        if item[len(item) - 1] == '.':
            del item[len(item) - 1]

    ## step 5
    if len(item) == 0:
        item.append('a'); item.append('a'); item.append('a')

    # step 6
    if len(item) >= 16:
        while True:
            del item[len(item) - 1]
            if len(item) == 15:
                if item[14] == '.':
                    del item[14]
                break

    # step 7
    if len(item) <= 2:
        while True:
            item.append(item[len(item) - 1])
            if len(item) == 3:
                break

    # list --> string
    for i in range(len(item)):
        answer += item[i]
        
    return answer