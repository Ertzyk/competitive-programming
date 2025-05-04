n = int(input())
if n == 1:
    print(1)
elif n == 2:
    print(2)
elif n == 3:
    print(4)
elif n == 4:
    print(8)
elif n == 5:
    print(16)
elif n == 6:
    print(32)
else:
    c1, c2, c3, c4, c5, c6 = 1, 2, 4, 8, 16, 32
    for _ in range(n - 6):
        c1, c2, c3, c4, c5, c6 = c2, c3, c4, c5, c6, (c1 + c2 + c3 + c4 + c5 + c6)%(10**9+7)
    print(c6)