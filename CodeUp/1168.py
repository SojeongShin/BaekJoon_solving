birth, gender = input().split()
gender = int(gender)

if(gender == 1):
    birth_year = int('19' + birth[0:2])
    print(2012 - birth_year + 1)
elif(gender == 2):
    birth_year = int('19' + birth[0:2])
    print(2012 - birth_year + 1)
elif(gender == 3):
    birth_year = int('20' + birth[0:2])
    print(2012 - birth_year + 1)
else:
    birth_year = int('20' + birth[0:2])
    print(2012 - birth_year + 1)
