for _ in range(int(input())):
    n = int(input())
    l, res = [], 0
    for _ in range(n):
        a = list(map(int, input().split()))
        count_1 = 0
        for i in range(n - 1, -1, -1):
            if a[i] == 1:
                count_1 += 1
            else:
                break
        l.append(count_1)
    l.sort()
    for i in range(n):
        if l[i] >= res:
            res += 1
    print(res)