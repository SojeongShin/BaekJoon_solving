num = input().split()
double = 0
for i in range(5):
    double += int(num[i])**2

print(double%10)