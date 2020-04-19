MOD = 10000007
def shokou(i):
    return (i*(i-1))//2
def makkou(i,n):
    return ((2*n+1-i)*i)//2

n,k = map(int, input().split())
ans = 0
for i in range(k,n+2):
    ans = (ans + makkou(i,n)-shokou(i)+1+MOD)%MOD
print(ans)
