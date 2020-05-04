n = int(input())
a = list(map(int, input().split()))

wa = {}
ans = 0
for i in range(len(a)):
    temp_wa = (i + 1) + a[i]
    if temp_wa in wa.keys():
        wa[temp_wa]+=1
    else:
        wa[temp_wa] = 1

    temp_sa = (i+1) - a[i]
    if temp_sa in wa.keys():
        ans += wa[temp_sa]

print(ans)
