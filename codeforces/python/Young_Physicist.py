sum_x, sum_y, sum_z = 0, 0, 0
for _ in range(int(input())):
    x, y, z = map(int, input().split())
    sum_x += x
    sum_y += y
    sum_z += z
print("YES" if sum_x == 0 and sum_y == 0 and sum_z == 0 else "NO")
