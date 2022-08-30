# 1264 모음의 개수

aeiou = ['a', 'e', 'i', 'o', 'u']
res = []

while True:
    sentence = input().lower()
    if sentence == '#':
        break
    else:
        cnt = 0
        for i in sentence:
            if i in aeiou:
                cnt += 1
        res.append(cnt)

print(*res, sep='\n')