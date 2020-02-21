import collections

n = int(input())

s = []
for _ in range(n):
    s.append(input())

c = collections.Counter(s)
common = c.most_common()
ans = []
idx = common[0][1]
for i in common:
    if idx == i[1]:
        ans.append(i[0])
    else:
        pass

for i in sorted(ans):
    print(i)
