for _ in range(int(input())):
    n, k = map(int, input().split())
    if n%2:
        print(1, (n - 1)//2, (n - 1)//2)
    else:
        if n%4:
            print(2, (n - 2)//2, (n - 2)//2)
        else:
            print(n//4, n//4, n//2)