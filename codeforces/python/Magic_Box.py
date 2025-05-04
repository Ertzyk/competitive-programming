x, y, z = map(int, input().split())
x1, y1, z1 = map(int, input().split())
a1, a2, a3, a4, a5, a6 = map(int, input().split())
result = a1 if y < 0 else a2 if y > y1 else 0
result += a3 if z < 0 else a4 if z > z1 else 0
result += a5 if x < 0 else a6 if x > x1 else 0
print(result)