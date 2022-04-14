n = int(input())
sum = 0
list = list(map(int, input().split()))
for i in list:
    if i % 5 == 0:
        sum+=i
print(sum)