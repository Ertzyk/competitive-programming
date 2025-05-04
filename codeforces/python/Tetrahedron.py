n = int(input())
if n == 1:
    print(0)
else:
    a, b = 0, 1
    for _ in range(n - 2):
        a, b = b, (3*a+2*b)%(10**9+7)
    print((3*b)%(10**9+7))