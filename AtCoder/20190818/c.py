n = int(input())

value = map(int, input().split())

value = sorted(value)

while len(value) > 1:
    value_0 = (value[0] + value[1]) / 2
    new = [value_0]
    for i in range(2,len(value)):
        new.append(value[i])
    value = new

print(value[0])
