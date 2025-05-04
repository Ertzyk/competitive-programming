def time(x0, n, x, c):
    max_value = 0
    for i in range(n):
        max_value = max(max_value, c[i] + abs(x[i] - x0))
    return max_value

t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    c = list(map(int, input().split()))
    l, r = min(x), max(x)
    while r - l > 1e-7:
        m1 = l + (r - l)/3
        m2 = r - (r - l)/3
        if time(m1, n, x, c) < time(m2, n, x, c):
            r = m2
        elif time(m1, n, x, c) > time(m2, n, x, c):
            l = m1
        else:
            l = m1
            r = m2
    print((l+r)/2)