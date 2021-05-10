n = int(input())
C = input()

ans = 0

color = [C[0]]
c = [0]
for i in range(len(C)):
    if C[i] == color[-1]:
        c[-1] += 1

    else:
        color.append(C[i])
        c.append(1)

idx_w = 0
idx_r = len(c) - 1
while True:
    if color[idx_w] != 'W':
        idx_w += 1
    if color[idx_r] != 'R':
        idx_r -= 1

    if idx_w == len(c) or idx_r == 0:
        break
    # print(idx_w)

    ans += min(c[idx_r], c[idx_w])
    if c[idx_w] < c[idx_r]:
        c[idx_r] -= c[idx_w]
        c[idx_w] = 0
        idx_w +=1
    else:
        c[idx_w] -= c[idx_r]
        c[idx_r] = 0
        idx_r -=1

    if idx_w + 1 >= idx_r or idx_w == len(c) or idx_r == 0:
        break

for i in range(len(c)):
    if color[i] == 'W' and c[i] != 0 :
        for j in range(i, len(c)):
            if color[i] == 'R' and c[i] == 

print(ans)
