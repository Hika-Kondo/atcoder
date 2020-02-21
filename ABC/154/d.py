n, k =  map(int,input().split())

p = list(map(int,input().split()))
counter_li = []
first = 0
for i in range(k):
    first+=p[i]
counter_li.append(first)
for i in range(1,len(p)-k+1):
    counter_li.append(counter_li[i-1]+ p[i+k-1] - p[i-1])
print(max(counter_li)/2+k/2)
