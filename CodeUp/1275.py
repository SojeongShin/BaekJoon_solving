# k 제곱 구하기
n, k = input().split()
n = int(n)
k = int(k)
res = 1
if k == 0:
    print(1)
else:
    for i in range(k):
        res *= n
    print(res)
