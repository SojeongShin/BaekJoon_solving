# 한라산 등반
n = int(input())
num = list(map(int,input().split()))
a, b = input().split()
a = int(a)
b = int(b)

result = 0
tmp = 0
cnt = 0

for i in range(a-1,b):
    result += num[i]

for i in range(n):
    for j in range(n):
        tmp = sum(num[i:j+1])
        if tmp == result:
            cnt += 1
print(cnt)