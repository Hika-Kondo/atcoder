import collections
from operator import mul
from functools import reduce

def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

N = int(input())
s = [input() for _ in range(N)]
split_s = [''.join(sorted([j for j in i])) for i in s]

c = collections.Counter(split_s)
ans = 0
for i in c.values():
    if i > 1:
        ans += cmb(i,2)

print(ans)
