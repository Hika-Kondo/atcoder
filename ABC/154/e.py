import math
def comb(n, r):
    if n==r:
        return 1
    elif n < r:
        return 0
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

n = int(input())
k = int(input())

# 桁数
keta = len(str(n))

if k == 1:
    top = int(str(n)[0])
    print(top + (keta-1)*9)
    exit()
elif k == 2:
    if keta < 2:
        print(0)
        exit()

    top1 = int(str(n)[0])
    top2 = int(str(n)[1])
    print(comb(keta - 1, 2) * 9 ** 2 + top2 + (keta-2) * 9 + (top1 - 1) * comb(keta - 1, 1)*9)
    exit()
else:
    if keta < 3:
        print(0)
        exit()
    top1 = int(str(n)[0])
    top2 = int(str(n)[1])
    top3 = int(str(n)[2])
    print(comb(keta-2, 3) * 9 ** 3 + # keta - 2 のときの数字の総和
    top3 + (keta-3) * 9 + # top1, top2固定
    (top2 - 1) * comb(keta - 2 ,1) * 9 + comb(keta-2, 2) * 9 ** 2 + # top1固定
    (top1 - 1) * comb(keta - 1, 2) * 9 ** 2)
    exit()
