a, b, c = map(str, input().split())

if a == b and b != c:
    print("Yes")
    exit()
elif a == c and b != a:
    print("Yes")
    exit()
elif b == c and a != b:
    print("Yes")
else:
    print("No")
