from collections import Counter

n, x, y = map(int, input().split())

ans = [0]*((10**3)*3)
counter = 0
for i in range(n-1):
    for j in range(i+1,n):
        # ショートカットできない場合
        # print(i,j)
        if j < x:
            temp = j-i
            ans[counter] = temp
        else:
            shortcut = abs((x-1) - i) + 1 + abs((y-1) -j )
            not_shortcut = j-i
            temp = min(shortcut,not_shortcut)
            ans[counter] = temp
        counter+=1
        # print(temp)

for i in range(1,n):
    print(ans.count(i))
