n = int(input())
s = input()
ans = 0
ans_list = []

R_index = []
G_index = []
B_index = []

for i in range(n):
    if s[i] == 'R':
        R_index.append(i)
    elif s[i] == 'G':
        G_index.append(i)
    elif s[i] == 'B':
        B_index.append(i)

ans = len(R_index) * len(G_index) * len(B_index)

for j in range(1, n-1):
    for i in range(min(n-j-1,j)+1):
        # print(j,i)
        # print(min(n-j-1,j))
        #
        # print(s[j-i],s[j],s[j+i])
        if s[j-i] != s[j] and s[j] != s[j+i] and s[j-i] != s[j+i]:
            # print('here')
            ans -= 1

print(ans)
