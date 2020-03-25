s = input()
q_ = int(input())

s = list(s)
# s = s[::-1]
for _ in range(q_):
    q = input()
    if q[0] == '1':
        s = s[::-1]
    else:
        q = q.split(' ')
        if q[1] == '1':
            s.insert(0,q[-1])
        else:
            s.extend(q[-1])
print(''.join(s))
