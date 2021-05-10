n,k = map(int,input().split())
s = input()

tot = 1
itm = []
cot = []
for i in range(len(s)):
    if i == 0:
        tot+=1
    elif s[i-1] == s[i]:
        tot+=1
    else:
        itm.append(tot)
        tot = 1
        if s[i] == '0':
            cot.append(1)
        else:
            cot.append(0)

itm.append(tot)
cot.append(s[-1])

ans = []
tmp = 0
if cot[0]:
    for i in range(2 * k + 1):
        tmp += itm[i]
    start = 2 * k + 1
else:
    for i in range(2 * k):
        tmp += itm[i]
    start = 2 * k
ans.append(tmp)
for i in range(start,len(itm)):
    tmp += itm[i]
    if cot[i]: 
        ans.append(tmp)
    else:
        if k == 1:
            tmp -= itm[i - 2]
        else:
            tmp -= itm[i - 2 * k - 1] + itm[i - 2 * k]
        ans.append(tmp)

print(max(ans))
