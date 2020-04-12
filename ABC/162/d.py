n = int(input())
s = input()

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

ans = 0
# print(R_index)
# print(G_index)
# print(B_index)

for i in R_index:
    for j in G_index:
        for k in B_index:
            temp_i = min(i,j,k)
            temp_k = max(i,j,k)
            temp_j = i + j + k - temp_i - temp_k
            if temp_k - temp_j == temp_j - temp_i:
                continue
            ans += 1


print(ans)
