def euclid(a, b):
    if b == 0:
        return a
    return euclid(b, a%b)

T = int(input())
for _ in range(T):
    ang = int(input())
    x = 180//euclid(ang, 180)
    print(x if ang <= (x-2)/x*180 else 2*x)