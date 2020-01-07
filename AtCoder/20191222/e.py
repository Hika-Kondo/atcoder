n = int(input())
INF = -100000
def f(n, li):
    if n < 2:
        li[n] = 1
    elif li[n-2] != INF:
        li[n] = n * li[n-2]


li = [INF] * (n+1)
li[0] = 1
for i in range(n):

    f(i+1,li)
ans = li[-1]
counter = 0
while True:
    if ans % 10 == 0:
        counter+=1
        ans = ans / 10
    else:
        break
print(counter)
