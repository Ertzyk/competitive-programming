t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    results = []
    for _ in range(q):
        l, u = map(int, input().split())
        r = l
        s, temp = a[r - 1], 0
        while r < n and s < u:
            temp = s
            s += a[r]
            r += 1
        if (2 * u - temp + 1) * temp // 2 >= (2 * u - s + 1) * s // 2:
            results.append(r - 1)
        else:
            results.append(r)
    print(*results)