n = input()
if n == n[::-1]:
    zenhan = n[0:int(len(n)//2)]
    if zenhan == zenhan[::-1]:
        kouhan = n[int(len(n)//2)+1::]

        if kouhan == kouhan[::-1]:
            print('Yes')
            exit()

print('No')
