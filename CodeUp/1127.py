# 1127 성적 계산

sum = 0.0
for i in range(3):
    a, b = input().split()
    ratio = float(a)
    score = float(b)

    res = ratio * score
    sum += res

print("%.1f" %sum)