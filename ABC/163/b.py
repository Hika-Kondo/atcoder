n, m =  map(int,input().split())
a = list(map(int,input().split()))
sum_a = sum(a)
ans = n-sum_a
if ans < 0:
    ans = -1
print(ans)
