for _ in range(int(input())):
    n = list(map(int, input()))
    for i in range(len(n) - 1, 0, -1):
        for j in range(i):
            if (n[j] + n[j + 1])%2 and n[j] > n[j + 1]:
                n[j], n[j + 1] = n[j + 1], n[j]
    print(*n, sep = "")