from copy import deepcopy

k, n = map(int, input().split())

a = list(map(int, input().split()))
a = sorted(a)
max_ = max(a)
min_ = min(a)
a_ = deepcopy(a)
ans = 100000000000
for index in range(len(a)):
    # temp = max(a) - min(a)
    # print(max_,min_)
    temp = max_ - min_
    max_ = min_ + k
    if index != len(a)-1:
        min_ = a[index+1]
    a[index] = a[index] + k
    # print(temp)
    if ans > temp:
        ans = temp

max_ = max(a_)
min_ = min(a_)

for index in reversed(range(len(a))):
    # print(a_, temp, max(a_), min(a_))
    # temp = (max(a_) - min(a_))
    # print(max_,min_)
    temp = max_-min_
    min_ = max_ -k
    if index != 0:
        max_ = a_[index-1]
    # print(temp)
    # a_[index] -= k
    if ans > temp:
        ans = temp

print(ans)
