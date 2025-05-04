for _ in range(int(input())):
    a1, a2, a4, a5 = map(int, input().split())
    a3_1, res1, res2, a3_2 = a1 + a2, 1, 1, a5 - a4
    if a2 + a3_1 == a4:
        res1 += 1
    if a3_1 + a4 == a5:
        res1 += 1
    if a1 + a2 == a3_2:
        res2 += 1
    if a2 + a3_2 == a4:
        res2 += 1
    print(max(res1, res2))