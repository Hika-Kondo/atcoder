n, m = map(int, input().split())
s, c = [], []
for i in range(m):
    temp_s, temp_c = map(int, input().split())
    s.append(temp_s)
    c.append(temp_c)

for i in range(1000):
    li = list(str(i))
    if len(li) == n:
        for idx in range(m):
            # print(li)
            if li[s[idx] - 1] == str(c[idx]):
                print(s[idx],c[idx],idx)
                pass
            else:
                break
        if idx == m-1:
            print(idx)
            print(''.join(li))
            exit()
print(-1)
