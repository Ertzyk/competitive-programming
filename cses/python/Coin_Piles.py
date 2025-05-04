for _ in range(int(input())):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    print("NO" if 2*a < b or (a + b)%3 else "YES")