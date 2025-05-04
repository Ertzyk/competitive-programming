t = int(input())
for _ in range(t):
    n = int(input())
    a, result = [], 0
    for i in range(n):
        row = list(map(int, input().split()))
        a.append(row)
    for i in range(n):
        min_val = 0
        for j in range(i+1):
            min_val = min(min_val, a[n-i+j-1][j])
        result -= min_val
    for i in range(n-1):
        min_val = 0
        for j in range(i+1):
            min_val = min(min_val, a[j][n-i+j-1])
        result -= min_val
    print(result)