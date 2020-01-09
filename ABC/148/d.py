N = int(input())
a = list(map(int, input().split()))

counter = 0
idx = 1
# ans = []
for i in range(N):
    if idx != a[i]:
        counter+=1
    else:
        idx += 1
if idx != 1:

    print(counter)

elif N == 0:
    if a[0] == 1:
        print(0)
else:
    print(-1)
