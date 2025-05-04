for _ in range(int(input())):
    n = int(input())
    print(n*(n + 1)*(4*n - 1)//6, 2*n)
    s = [j + 1 for j in range(n)]
    for i in range(n):
        x = [1, n - i] + s
        print(*x)
        x = [2, n - i] + s
        print(*x)