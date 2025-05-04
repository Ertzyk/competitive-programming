n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
if n > m:
    print(0)
else:
    result = 1
    for i in range(n):
        for j in range(i+1, n):
            result *= abs(a[i]-a[j])%m
            result %= m
    print(result)