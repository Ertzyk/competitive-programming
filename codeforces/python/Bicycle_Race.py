n = int(input())
x0, y0 = list(map(int, input().split()))
prev_direction, result = 0, 0
for i in range(n):
    x1, y1 = list(map(int, input().split()))
    direction = 1 if x1 > x0 else 3 if x1 < x0 else 0 if y1 > y0 else 2
    if (direction - prev_direction)%4 == 3:
        result += 1
    x0, y0, prev_direction = x1, y1, direction
print(result)