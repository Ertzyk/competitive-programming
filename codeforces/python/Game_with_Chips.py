n, m, k = map(int, input().split())
s, f = [], []
for _ in range(k):
    x, y = map(int, input().split())
    s.append((x, y))
for _ in range(k):
    x, y = map(int, input().split())
    f.append((x, y))
a, b = max(map(lambda x: x[0] - 1, s)), max(map(lambda x: x[1] - 1, s))
result, dir_row = "L" * b + "U" * a, 0
for i in range(n):
    result += "R"*(m - 1) if dir_row == 0 else "L" * (m - 1)
    dir_row = (dir_row + 1) % 2
    result += "D"
result = result[:-1]
print(len(result))
print(result)