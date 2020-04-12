def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)

n = int(input())

ans = 0
# 3つすべて同じ場合
for i in range(1,n+1):
    ans += i


# 2つ同じ時
if n> 1:
    for i in range(1,n+1):
        for k in range(i+1,n+1):

            ans += gcd(i,k) * 6


# 3つ違う時
if n > 2:
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            for l in range(j+1,n+1):
                ans += gcd(i,gcd(j, l)) * 6


print(ans)
