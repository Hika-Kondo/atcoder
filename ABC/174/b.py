import numpy as np

n, d = map(int, input().split())

ans = 0

for i in range(n):
    tmp_x, tmp_y = map(int, input().split())
    distance = np.sqrt(np.square(tmp_x) + np.square(tmp_y))
    if distance <= d:
        ans += 1

print(ans)

