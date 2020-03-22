from collections import Counter

d = int(input())
a = list(map(int, input().split()))

Counted_A = Counter(a)

comp_dict = {}
not_dict = {}
for i in Counted_A.items():
    comp_dict[i[0]] = i[1]*(i[1]-1)/2
    not_dict[i[0]] = (i[1]-1)*(i[1]-2)/2

ans = 0
for i in comp_dict.items():
    ans += i[-1]


for i in a:
    temp = ans - comp_dict[i] + not_dict[i]
    print(int(temp))
