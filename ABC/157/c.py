n, m = map(int, input().split())
s, c = [], []
for i in range(m):
    temp_s, temp_c = map(int, input().split())
    s.append(temp_s)
    c.append(temp_c)

ans = ['0'] * n

for i in range(m):

    if s[i] == 1 and c[i] == 0 and n != 1:
        print(-1)
        exit()

    str_c = str(c[i])
    if ans[s[i] - 1] == '0' or ans[s[i] - 1] == str_c:
        ans[s[i] - 1] = str_c

    else:
        print(-1)
        exit()

if ans[0] == 0:
    ans[0] = '1'

print(int(''.join(ans)))
