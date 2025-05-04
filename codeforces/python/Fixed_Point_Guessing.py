for _ in range(int(input())):
    n = int(input())
    l, r = 1, n
    while l < r:
        m = (l + r)//2
        print(f"? {l} {m}", flush = True)
        if len(set(map(int, input().split()))&{i for i in range(l, m + 1)})%2:
            r = m
        else:
            l = m + 1
    print(f"! {l}")