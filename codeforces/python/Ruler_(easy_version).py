for _ in range(int(input())):
    x, l, r = 999, 2, 999
    while l <= r:
        m = (l + r) // 2
        print(*["?", str(m), str(m)], flush = True)
        responce = input()
        if m**2 == int(responce):
            l = m + 1
        else:
            x, r = m, m - 1
    print(*["!", str(x)], flush = True)