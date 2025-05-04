n = int(input())
if 1 < n < 4:
    print("NO SOLUTION")
else:
    print(*[i for i in range(2, n + 1, 2)] + [i for i in range(1, n + 1, 2)])