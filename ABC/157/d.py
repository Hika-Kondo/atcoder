n, m, k = map(int, input().split())
a, b = [], []
c, d = [], []

ans = [[0]*n for i in range(n)]
print(ans)
for i in range(n):
    ans[i][i] = -1
for i in range(m):
    temp_a, temp_b = map(int, input().split())
    ans[temp_a-1][temp_b-1] = 1
    ans[temp_b-1][temp_a-1] = 1

for i in range(k):
    temp_c, temp_d = map(int, input().split())
    ans[temp_c-1][temp_d-1] = -1
    ans[temp_d-1][temp_c-1] = -1

print(ans)
