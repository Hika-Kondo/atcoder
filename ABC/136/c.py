n = int(input())
h = list(map(int,input().split()))

flag = True
count = 0
for i in range(len(h)-1):
    if h[i] < h[i + 1]:
        count = 0
    else:
        count += h[i] - h[i+1]
        if count >= 2:
            flag = False
            print('No')
            exit()

print('Yes')
