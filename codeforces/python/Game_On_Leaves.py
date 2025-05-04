for _ in range(int(input())):
    n, x = map(int, input().split())
    x_degree = 0
    for _ in range(n - 1):
        u, v = map(int, input().split())
        if x_degree < 2 and (u == x or v == x):
            x_degree += 1
    print("Ashish" if x_degree > 1 and n%2 else "Ayush")