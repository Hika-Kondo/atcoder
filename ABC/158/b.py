n, a, b = map(int, input().split())

# 青がa,赤がb

# n番目の数は赤or青

remainder = n % (a + b)
if remainder > a:
    print((n//(a+b)) * a + a)
else:
    print(remainder + (n //(a+b))* a)
