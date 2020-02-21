n, k = map(int, input().split())
a = list(map(int, input().split()))

a = sorted(a)

minus = sorted([i for i in a if i < 0])
zero = sorted([i for i in a if i == 0])
plus = sorted([i for i in a if i > 0])
# 答えがマイナスになる時

for i in range(len(minus)):
    if k > len(plus):
        k -= len(plus)
    else:
        print(minus[i]*plus[-k])
        exit()

# 答えがゼロの時
num_zero = len(zero)*(len(minus) + len(plus)) + (len(zero)*(len(zero) - 1) ) * 0.5

if k > num_zero:
    k -= num_zero
else:
    print(0)
    exit()


# 答えがプラスの時
idx = 0
while True:
    num_plus = len(plus) - idx - 1 if (len(plus) - idx - 1) > 0 else 0
    num_minus = len(minus) - idx - 1 if (len(minus) - idx - 1) > 0 else 0
    if k > num_minus + num_plus:
        k -= num_minus + num_plus
    else:
        ansli = []
        for i in range(len(plus)-idx-1):
            ansli.append(plus[idx]*plus[idx + i+1])
        for i in range(len(minus) - idx - 1 ):
            ansli.append(minus[idx]*minus[idx + i+1])
        ansli = sorted(ansli)
        print(ansli[int(k)-1])
        exit()
    idx += 1

print(k)
