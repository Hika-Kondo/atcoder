n,m,q = map(int,input().split())
inp_dic = {}
ans = 0
retu = pow(10,n-1)

a = []
b = []
c = []
d = []
for _ in range(q):
    temp_a, temp_b, temp_c, temp_d = map(int,input().split())
    a.append(temp_a)
    b.append(temp_b)
    c.append(temp_c)
    d.append(temp_d)


while (True):
    if (retu >= pow(10,n)):
        break
    flag = False
    temp_retu = retu
    for i in range(n):
        matu = retu % 10
        temp_retu = int(retu/10)
        if ( matu < temp_retu):
            falg = True
        if (matu > m):
            flat = True
        if (retu == 0):
            break

    if (flag):
        continue

    li = [int(i) for i in list(str(retu))]
    point = 0
    for i in range(q):
        if (li[b[i]-1] - li[a[i]-1] == c[i]):
            point += d[i]
        if (point > ans):
            ans = point

    retu += 1
print(ans)
