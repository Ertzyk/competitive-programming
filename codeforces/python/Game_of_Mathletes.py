for _ in range(int(input())):
    n, k = map(int, input().split())
    x = list(map(int, input().split()))
    res, s, p, e = 0, max(1, k - n), [0]*(n + 1), min(n + 1, (k - 1)//2 + 1)
    for i in x:
        p[i] += 1
    for i in range(s, e):
        res += min(p[i], p[k - i])
    if k%2 == 0:
        res += p[k//2]//2
    print(res)