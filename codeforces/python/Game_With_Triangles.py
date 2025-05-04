for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if n >= 2*m:
        print(m)
    elif m >= 2*n:
        print(n)
    else:
        print((n + m)//3)