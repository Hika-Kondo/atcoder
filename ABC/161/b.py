n, m = map(int, input().split())
a = list(map(int, input().split()))

min_ = sum(a)/(4*m)
ans = 0
for i in a:
    if i >= min_:
        ans += 1

if ans >= m:
    print('Yes')
else:
    print('No')
