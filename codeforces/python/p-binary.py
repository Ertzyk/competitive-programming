n, p = map(int, input().split())
i = 0
while n - p*i > 0 and 2**(i - 1) <= n - p*i:
    b, count_1 = n - p*i, 0
    while b:
        b &= b - 1
        count_1 += 1
    if count_1 <= i:
        print(i)
        break
    i += 1
else:
    print(-1)