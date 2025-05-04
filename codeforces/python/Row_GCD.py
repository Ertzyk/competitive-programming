import math
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if n == 1:
    print(*[a[0] + b[i] for i in range(m)])
else:
    c = a[1] - a[0]
    for i in range(2, n):
        c = math.gcd(c, a[i] - a[0])
    print(*[math.gcd(c, a[0] + b[i]) for i in range(m)])