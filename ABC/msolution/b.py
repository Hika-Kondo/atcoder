a, b, c = map(int, input().split())

k = int(input())

ans = 0

while True:
    if b <= a:
        b *= 2
        ans+=1
    elif c <= b:
        c *= 2
        ans += 1
    if a < b and b < c:
        break
if ans > k:
    print('No')
else:
    print('Yes')
