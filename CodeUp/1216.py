# 컨설팅회사
no, yes, cost = input().split()
no = int(no)
yes = int(yes)
cost = int(cost)
if (no > yes - cost):
    print("do not advertise")
elif(no < yes - cost):
    print("advertise")
else:
    print("does not matter")