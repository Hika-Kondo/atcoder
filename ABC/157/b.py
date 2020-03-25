a = []

for i in range(3):
    b = list(map(int, input().split()))
    a.append(b)
n = int(input())
b = []
for i in range(n):
    b.append(int(input()))

ans = [[0,0,0], [0,0,0], [0,0,0]]
for num_b in range(n):
    for i in range(3):
        for j in range(3):
            if b[num_b] == a[i][j]:
                ans[i][j] = 1

for i in range(3):
    if ans[i][0] == 1 and ans[i][1] == 1 and ans[i][2] == 1:
        print('Yes')
        exit()
    if ans[0][i] == 1 and ans[1][i] == 1 and ans[2][i] == 1:
        print('Yes')
        exit()
    if ans[0][0] == 1 and ans[1][1] == 1 and ans[2][2] == 1:
        print("Yes")
        exit()
    if ans[2][0] == 1 and ans[1][1] == 1 and ans[0][2] == 1:
        print("Yes")
        exit()
print("No")
