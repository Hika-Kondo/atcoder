x = int(input())

happy_500 = x//500
x %= 500

happy_5 = x // 5

print(happy_500 * 1000 + happy_5 * 5)
