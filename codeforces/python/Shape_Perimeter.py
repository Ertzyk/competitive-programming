for _ in range(int(input())):
    n, m = map(int, input().split())
    p = 4*m*n
    for i in range(n):
        x, y = map(int, input().split())
        if i > 0:
            p -= 2*(m - x) + 2*(m - y)
    print(p)