def sousa(x, k):
    return abs(x-k)

n,k = map(int, input().split())

ans = min(n%k, k - n%k)
print(ans)
