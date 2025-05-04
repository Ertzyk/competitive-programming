for _ in range(int(input())):
    n, k = map(int, input().split())
    cur, result, p = 1, [0]*n, k - 1
    while p < n:
        result[p] = cur
        cur += 1
        p += k
    for i in range(len(result)):
        if result[i] == 0:
            result[i] = cur
            cur += 1
    print(*result)