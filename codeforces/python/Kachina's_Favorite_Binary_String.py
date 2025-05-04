for _ in range(int(input())):
    n = int(input())
    c, p = [0], 0
    for i in range(n - 1):
        print(f"? {1} {i + 2}")
        c.append(int(input()))
    while p < n and c[p] == 0:
        p += 1
    if p == n:
        print("! IMPOSSIBLE", flush = True)
    else:
        res, prev = "1"*(p - c[p]) + "0"*c[p] + "1", c[p]
        for i in range(p + 1, n):
            if c[i] > prev:
                res += "1"
                prev = c[i]
            else:
                res += "0"
        print(f"! {res}", flush = True)