for _ in range(int(input())):
    m, a, b, c = map(int, input().split())
    print(min(min(m, a) + min(m, b) + c, 2*m))