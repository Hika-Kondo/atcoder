MOD = 1000000007
NCK_MAX = 510000

fac = [0 for _ in range(NCK_MAX)]; finv = [0 for _ in range(NCK_MAX)]
inv = [0 for _ in range(NCK_MAX)]; facn = [0 for _ in range(NCK_MAX)]

def myPow(x,n,MOD=MOD):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return myPow(x*x%MOD,n//2)
    else:
        return x*myPow(x,n-1)%MOD

def COMinit(n):
    fac[0] = 1; fac[1] = 1
    facn[1] = n
    finv[0] = 1; finv[1]=1
    inv[1]=1
    for i in range(2,NCK_MAX):
        fac[i] = fac[i-1]*i%MOD
        facn[i] = facn[i-1]*(n-i+1)%MOD
        inv[i] = MOD-inv[MOD%i]*(MOD//i)%MOD
        finv[i] = finv[i-1]*inv[i]%MOD

def modinv(a,MOD=MOD):
    return myPow(a,MOD-2)

def COM(n,k):
    if n<k:
         return 0
    elif n<0 and k<0:
         return 0
    return facn[k] * finv[k]%MOD
    
# SEE HOW TO USE in ABC/156/d.py