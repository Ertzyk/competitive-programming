t = int(input())
for i in range(t):
    n = int(input())
    h = list(map(int, input().split()))
    res, j = 1, 0
    while j < n - 1:
        s = 1
        while j < n - 1 and h[j] == h[j + 1]:
            s += 1
            j += 1
        res = max(res, s)
        j += 1
    print(n - res)