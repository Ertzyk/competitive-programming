for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    a, b = x2 - x1, y2 - y1
    print(min(a, b)*(a + b - min(a, b)) + 1)