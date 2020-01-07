n = int(input())
comments = {}
for i in range(n):
  a = int(input())
  comments[i] = []
  for _ in range(a):
    x, y = [int(x) for x in input().split()]
    comments[i].append([x-1, y==1])

ans = 0
for i in range(2**n):
  results = [None] * n
  for j in range(n):
    candidate = ((i >> j) & 1) == 1
    if results[j] is None:
      results[j] = candidate
    elif results[j] != candidate:
      break
    if candidate == False:
      continue
    elif candidate == True:
      failed = False
      for comment in comments[j]:
        if results[comment[0]] is None:
          results[comment[0]] = comment[1]
        if results[comment[0]] != comment[1]:
          failed = True
          break
      if failed:
        break
  else:
    cnt = len([r for r in results if r is True])
    if cnt > ans:
      ans = cnt

print(ans)
