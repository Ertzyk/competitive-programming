t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())), reverse=True)
    p = a.pop() if n%2 else 0
    res = 0
    for i in range(0, len(a), 2):
        res += a[i] - a[i+1]
    res -= k
    res = max(res, 0)
    res += p
    print(res)