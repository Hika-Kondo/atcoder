a,b = map(int, input().split())

x_b = b * 10

min_a = (25/2) * a
max_a = (25/2) * (a + 1)

min_b = 10 * b
max_b = 10 * (b + 1)

min_ = max(min_a, min_b)
max_ = min(max_a, max_b)

_min = int(min_ + 0.5)
_max = int(max_)

if _min >= _max:
    print(-1)

else:
    print(_min)
