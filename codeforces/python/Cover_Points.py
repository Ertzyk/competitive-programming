n, result = int(input()), 0
for _ in range(n):
    x, y = map(int, input().split())
    result = max(result, x + y)
print(result)