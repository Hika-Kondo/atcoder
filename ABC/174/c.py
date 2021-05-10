k = int(input())

tmp = 1

for i in range(100000):
    tmp *= k
    str_tmp = str(tmp)
    for s in str_tmp:
        flag = True
        if s != '7':
            flag = False

    if flag:
        break

if flag:
    print(len(str_tmp))

else:
    print(-1)
