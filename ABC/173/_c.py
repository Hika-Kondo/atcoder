from copy import deepcopy

def color(c,h,w):
    if len(h) != 0:
        for i in h:
            for j in range(W):
                c[i][j] = 'R'

    if len(w) != 0:
        for i in w:
            for j in range(H):
                c[j][i] = 'R'

    return c

def cunt(c):
    tot = 0
    for i in range(H):
        for j in range(W):
            if c[i][j] == "#":
                tot+=1
    return tot

H,W,K = map(int, input().split())
c = []
for i in range(H):
    tmp = list(input())
    c.append(tmp)

ans = 0

for i in range(2 ** H):
    for j in range(2 ** W):
        h = []
        w = []
        for  k in range(H):
            if ((i>>k) & 1):
                h.append(k)
        for k in range(W):
            if ((j >> k) & 1):
                w.append(k)
        _copy = deepcopy(c)
        tmp = color(_copy,h,w)
        # for _tmp in tmp:
            # print(_tmp)
        _cunt = cunt(tmp)
        # print(_cunt)
        if _cunt == K:
            ans+=1

print(ans)
