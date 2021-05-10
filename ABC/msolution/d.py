N = int(input())
A = list(map(int, input().split()))
money = 1000
stock = 0
 
for i in range(N):
    if i == N-1:
        money += stock * A[i]
        break
    if A[i] < A[i+1]:
        tmp_stock = money // A[i]
        stock += tmp_stock
        money -= tmp_stock * A[i]
    elif A[i] > A[i+1]:
        money += stock * A[i]
        stock = 0
    else:
        pass
 
print(money)
