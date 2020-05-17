from collections import defaultdict

class que(object):
    def __init__(self):
        self.item = []

    def push(self,x):
        self.item.append(x)
    
    def front(self):
        return self.item[0]
    
    def pop(self):
        self.item.pop(0)
    
    def empty(self):
        return len(self.item) == 0

n,m = map(int , input().split())
path = defaultdict(list)

ans = [-1]*n

for i in range(m):
    a,b = map(int, input().split())
    path[a-1].append(b-1)
    path[b-1].append(a-1)

q = que()

q.push(0)

ans[0] = 0

while not q.empty():
    now = q.front()
    q.pop()


    for tmp in path[now]:
        if tmp == now:
            continue
        
        if ans[tmp] != -1:
            continue
            
        else:
            ans[tmp] = now
            q.push(tmp)


for tmp in ans:
    if tmp == -1:
        print("No")
        exit()

print("Yes")

for tmp in ans[1:]:
    
    print(tmp+1)
            
