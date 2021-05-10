n = int(input())

alphabet =  ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z']


ans = ''
list = []
idx = 1
while True:
    print(n)
    if n > 26 ** idx:
        n = n - 26 ** idx
        idx += 1

    else:
        break

for i in range(idx):
    list.append(n % 26)
    n = n // 26

    if n <= 0:
        break

print(list)

for i in list:
    ans += alphabet[i-1]
    idx -= 1

ans = ans[::-1]

for i in range(idx):
    ans += 'a'

# for i in range(idx):
    # if len(list) - 1 < i:
        # ans+='a'
    # ans += alphabet[list[i]-1]

print(ans)
