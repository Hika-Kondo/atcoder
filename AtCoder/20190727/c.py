_ = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

counter = 0
for i in range(len(b)):
    counter += min(a[i],b[i])
    if b[i] - a[i] >= 0:
        c = b[i]-a[i]
        if a[i + 1] - c >= 0:
            a[i + 1] -= c
            counter += c
        else:
            counter += a[i + 1]
            a[i + 1] = 0

print(counter)
