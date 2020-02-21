def slove(h,counter):
    if h == 1:
        return counter + 1
    else:
        return 2 * slove(h//2,counter) + 1

h = int(input())

print(slove(h,0))
