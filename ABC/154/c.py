n = int(input())
a = list(map(int,input().split()))

dic = {}

for i in a:
    if i not in dic.keys():
        dic[i] = 1
    else:
        print("NO")
        exit()
print("YES")
