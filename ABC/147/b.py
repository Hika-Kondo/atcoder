s = input()
counter = 0
for i in range(len(s)//2):
    # print(s[i],s[len(s)-i-1])
    if s[i] == s[len(s)-i-1]:
        pass
    else:
        counter += 1
print(counter)
