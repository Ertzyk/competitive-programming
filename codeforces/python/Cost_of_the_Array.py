for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if n == k:
        b = []
        for i in range(1, n, 2):
            b.append(a[i])
        b.append(0)
        for i in range(len(b)):
            if b[i] != i + 1:
                print(i + 1)
                break
    else:
        a[0], count_1 = 1, 0
        for i in range(n):
            if a[i] == 1:
                count_1 += 1
            else:
                break
        if n - k + 1 < count_1 and count_1 > 2:
            print(2)
        else:
            print(1)