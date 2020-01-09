A, B = map(int, input().split())
def D(a):
    L = ["N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"]
    for i in range(17):
        if a <= i * 225 + 112: return L[i]
def E(a):
    L = [2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326, 10**10]
    for i in range(17):
        if a < 6 * L[i] + 3: return i

d,e = D(A), E(B)
if not e:
  d = 'C'
print(d,e)
