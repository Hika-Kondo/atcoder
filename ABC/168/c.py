import  numpy as np

def kaku(h,m):
    PI = 3.14159265358979323846
    hum = h * 60 + m
    rad = hum / 360 * PI
    return rad

def yogen(a, b, kaku):
    tmp = pow(a, 2) + pow(b, 2) - 2 * a * b * np.cos(kaku)
    return np.sqrt(tmp)
    

a,b,h,m = map(int, input().split())

hour_rad = kaku(h, m)
min_rad = kaku(0, m) * 12
rad = abs(min_rad - hour_rad)
ans = yogen(a, b, rad)
   

print(ans)