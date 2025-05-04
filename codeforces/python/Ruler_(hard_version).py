for _ in range(int(input())):
    x, l, r = 999, 2, 999
    while l <= r:
        m1 = l + (r-l)//3
        m2 = r - (r-l)//3
        print(*["?", str(m1), str(m2)], flush = True)
        responce = input()
        if int(responce) == m1*m2:
            l = m2 + 1
        elif int(responce) == m1*(m2 + 1):
            l, r, x = m1 + 1, m2 - 1, m2
        else:
            r, x = m1 - 1, m1
    print(*["!", str(x)], flush = True)