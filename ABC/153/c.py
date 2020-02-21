n, k = map(int, input().split())
h = list(map(int, input().split()))

h = sorted(h)
sum_of_k = 0
if k >= n:
    print(0)
    exit()
for i in range(k):
    sum_of_k += h[len(h)-i-1]
ans = sum(h)-sum_of_k
print(ans if ans >=0 else 0)
