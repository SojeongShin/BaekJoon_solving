# 행렬덧셈
N, M = map(int, input().split())
a = []
for i in range(N):
    a.append(list(map(int, input().split())))

for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(M):
        a[i][j] += temp[j]

for i in range(N):
    for j in range(M):
        print(a[i][j], end=" ")
    print()
