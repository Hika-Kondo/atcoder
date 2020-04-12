n =  int(input())

ans = 0
for i in range(n):
    temp = i + 1
    if temp % 5 != 0 and temp % 3 != 0:
        ans += temp

print(ans)
