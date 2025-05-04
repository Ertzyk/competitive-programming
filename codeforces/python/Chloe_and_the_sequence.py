n, k = map(int, input().split())
i = 1
while True:
    if k%2:
        print(i)
        break
    k //= 2
    i += 1