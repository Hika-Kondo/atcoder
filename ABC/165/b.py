x = int(input())
shoki = 100
ans = 0
while True:
    shoki = int(shoki * 1.01)
    ans+=1
    if shoki >= x:
        print(ans)
        break
