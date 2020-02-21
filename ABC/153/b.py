h, n = map(int, input().split())
a = list(map(int, input().split()))
sum_of_a = sum(a)
if h <= sum_of_a:
    print("Yes")
else:
    print("No")
