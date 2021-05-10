import collections

n = int(input())
a = list(map(int,input().split()))
q = int(input())

collect_dict = dict(collections.Counter(a))

now = sum(a)

ans = []
for i in range(q):
    b, c = map(int,input().split())
    if b not in collect_dict.keys():
        ans.append(now)
        continue
    now -= collect_dict[b] * b
    tmp = collect_dict[b]
    collect_dict.pop(b)
    if c not in collect_dict.keys():
        collect_dict[c] = 0
    collect_dict[c] += tmp
    now += c * tmp
    ans.append(now)

for i in ans:
    print(i)
