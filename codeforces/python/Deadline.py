import math

def f(x, d):
    return x + d/(x+1)

t = int(input())
for _ in range(t):
    n, d = list(map(int, input().split()))
    l, r = 0, d - 1
    while r - l > 1e-3:
        m1, m2 = l + (r - l)/3, r - (r - l)/3
        if f(m1, d) < f(m2, d):
            r = m2
        elif f(m1, d) > f(m2, d):
            l = m1
        else:
            l = m1
            r = m2
    print("YES" if math.floor((l + r)/2)+math.ceil(d/(math.floor((l + r)/2)+1)) <= n or math.ceil((l + r)/2) + math.ceil(d/(math.ceil((l + r)/2)+1)) <= n else "NO")