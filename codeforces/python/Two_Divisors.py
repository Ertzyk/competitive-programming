import math
for _ in range(int(input())):
    a, b = map(int, input().split())
    print(b**2 if a == 1 else b//a*b if b%a == 0 else a*b//math.gcd(a, b))