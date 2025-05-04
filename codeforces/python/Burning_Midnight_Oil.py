import math
n, k = map(int, input().split())
l, r, res = 1, n, float("inf")
while l <= r:
    m = (l + r)//2
    s, c = 0, m
    while c >= 1:
        s += math.floor(c)
        c /= k
    if s >= n:
        res, r = m, m - 1
    else:
        l = m + 1
print(res)