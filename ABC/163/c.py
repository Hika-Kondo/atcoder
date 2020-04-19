n = int(input())
a = list(map(int,input().split()))

a = [i-1 for i in a]
di = [0 for _ in range(n)]

for i in a:
    di[i] += 1

for i in range(len(di)):
    print(di[i])
