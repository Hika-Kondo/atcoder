h, a = map(int, input().split())
flag = False
if h % a != 0:
    flag = True

ans = h // a
if flag:
    ans += 1
print(ans)
