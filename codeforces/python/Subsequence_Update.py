for _ in range(int(input())):
    n, l, r = map(int, input().split())
    l -= 1
    r -= 1
    a = list(map(int, input().split()))
    if l == 0 and r == n - 1:
        print(sum(a))
    else:
        res = float('inf')
        if l > 0:
            x = sorted(a[:r + 1])
            res = sum(x[:r - l + 1])
        if r < n - 1:
            x = sorted(a[l:])
            res = min(res, sum(x[:r - l + 1]))
        print(res)