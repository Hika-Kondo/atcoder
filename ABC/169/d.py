import collections

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


n = int(input())

itm = collections.Counter(prime_factorize(n))

ans = 0

for i in itm.keys():
    num = 1
    while True:
        if itm[i] - num < 0:
            break
        else:
            ans+=1
            itm[i] -= num
            num += 1

counter = 0

for i in itm.keys():
    if itm[i] != 0:
        counter += 1
    
print(ans)