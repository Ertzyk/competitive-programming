n, k, q = map(int, input().split())
grid = [list(map(int, input().split()))]
for _ in range(n - 1):
    row = list(map(int, input().split()))
    for j in range(k):
        row[j] |= grid[-1][j]
    grid.append(row)
for _ in range(q):
    req = int(input())
    L, R = 0, n - 1
    for _ in range(req):
        re, o, c = input().split()
        if L <= R:
            l, r, re, c = L, R, int(re) - 1, int(c)
            if o == "<":
                res_max = -1
                while l <= r:
                    m = (l + r)//2
                    if grid[m][re] < c:
                        l = m + 1
                        res_max = m
                    else:
                        r = m - 1
                R = res_max
            else:
                res_min = r + 1
                while l <= r:
                    m = (l + r)//2
                    if grid[m][re] > c:
                        r = m - 1
                        res_min = m
                    else:
                        l = m + 1
                L = res_min
    print(L + 1 if L <= R else -1)