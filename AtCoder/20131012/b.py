m = int(input())

km = m / 1000

if km < 0.1:
    print('00')

elif km <= 5:
    print(str(int(km * 10)).zfill(2))

elif km >= 6 and km <= 30:
    print(str(int(km + 50)).zfill(2))

elif km >= 35 and km <= 70:
    print(str(int((km-30)/5 + 80)).zfill(2))

elif km >= 70:
    print(89)
