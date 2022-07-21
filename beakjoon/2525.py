# 오븐 시계
now_h, now_m = input().split()
need = int(input())

now_h = int(now_h)
now_m = int(now_m)

cnt = 0
fin_m = now_m+need

while fin_m >= 60:
    fin_m -= 60
    cnt += 1

fin_h = cnt + now_h

while fin_h >= 24:
    fin_h -= 24

print(fin_h, fin_m)