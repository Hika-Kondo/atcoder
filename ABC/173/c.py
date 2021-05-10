from copy import deepcopy

def cunt(c, h, w):
    tot = 0
    for i in range(h):
        for j in range(w):
            if c[i][j] == '#':
                tot+=1

    return tot

h,w,K = map(int, input().split())
c = []
for i in range(h):
    tmp = list(input())
    c.append(tmp)

ans = 0

# 横を塗って縦を塗る
for i in range(h):
    copy_c = deepcopy(c)
    for j in range(w):
        copy_c[i][j] = 'R'
    
    if cunt(copy_c,h,w) == K:
        ans+=1
    
    # for i in copy_c:
        # print(i)

    # print(cunt(copy_c,h,w),ans)
    # print()
    #縦を塗る
    # どの縦にするかのループ
    for j in range(w):
        _copy_c = deepcopy(copy_c)
        for k in range(h):
            _copy_c[k][j] = 'R'
        for i in _copy_c:
            print(i)
        print()
        if cunt(_copy_c, h, w) == K:
            ans+=1

        print(cunt(_copy_c,h,w),ans)

#縦だけ塗る
for i in range(w):
    copy_c = deepcopy(c)
    for j in range(h):
        copy_c[j][i] = 'R'

    if cunt(copy_c, h, w) == K:
        ans+=1

print(ans)


