n = int(input())
a = sorted(list(map(int, input().split())))
s = sum(a)
m = int(input())
for _ in range(m):
    x, y = map(int, input().split())
    p, q, l, r = 10**12+1, 0, 0, len(a) - 1
    while l <= r:
        m = (l + r) // 2
        if a[m] < x:
            l = m + 1
            q = a[m]
        else:
            r = m - 1
            p = a[m]
    print(min(max(y - s + p, 0) if p != 10**12+1 else float('inf'), x - q + max(y - s + q, 0) if q != 0 else float('inf')))