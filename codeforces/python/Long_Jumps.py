for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    result = 0
    for i in range(n - 1, -1, -1):
        if i + a[i] <= n - 1:
            a[i] += a[i + a[i]]
        result = max(result, a[i])
    print(result)