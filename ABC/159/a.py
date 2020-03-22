x,y = map(int,input().split())

# even + even
ans = x*(x-1) / 2

# odd + odd
ans += y*(y-1) / 2

print(int(ans))
