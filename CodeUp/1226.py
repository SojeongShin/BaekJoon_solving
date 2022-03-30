# 이번주 로또
lotto = list(map(int,input().split()))  # 보너스 번호까지 7개 숫자를 입력 받음
usr = list(map(int,input().split()))  # 사용자에게 6개 숫자를 입력 받음
cnt = 0  # 맞는 로또의 갯수

lotto_num = lotto[:6]  # 보너스 번호 뺴고 리스트 입력
bonus_num = lotto[-1]  # 보너스 번호 입력
bonus = False  # 보너스 숫자가 맞았는지 판단

lotto.sort()
usr.sort()

for i in lotto_num:
    if i in usr:
        cnt += 1
if bonus_num in usr:
    bonus = True

if cnt==6:
    print("1")
elif cnt==5 and bonus==True:
    print("2")
elif cnt==5:
    print("3")
elif cnt==4:
    print("4")
elif cnt==3:
    print("5")
else:
    print("0")

