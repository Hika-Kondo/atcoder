n = int(input())
s,t = input().split()

l = []
for i in range(n):
    l.append(s[i])
    l.append(t[i])

print(''.join(l))
