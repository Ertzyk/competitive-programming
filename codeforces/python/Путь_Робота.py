n, m = map(int, input().split())
grid, robot_cord, result, prev = [], [0, 0], "", [-1, -1]
for i in range(n):
    x = input()
    grid.append(x)
    if x.find("S") != -1:
        robot_cord = [i, x.find("S")]
while True:
    if robot_cord[0] > 0 and (grid[robot_cord[0] - 1][robot_cord[1]] == "*" or grid[robot_cord[0] - 1][robot_cord[1]] == "S") and (robot_cord[0] - 1 != prev[0] or robot_cord[1] != prev[1]):
        prev = [robot_cord[0], robot_cord[1]]
        result += "U"
        robot_cord[0] -= 1
    elif robot_cord[0] < n - 1 and (grid[robot_cord[0] + 1][robot_cord[1]] == "*" or grid[robot_cord[0] + 1][robot_cord[1]] == "S") and (robot_cord[0] + 1 != prev[0] or robot_cord[1] != prev[1]):
        prev = [robot_cord[0], robot_cord[1]]
        result += "D"
        robot_cord[0] += 1
    elif robot_cord[1] > 0 and (grid[robot_cord[0]][robot_cord[1] - 1] == "*" or grid[robot_cord[0]][robot_cord[1] - 1] == "S") and (robot_cord[0] != prev[0] or robot_cord[1] - 1 != prev[1]):
        prev = [robot_cord[0], robot_cord[1]]
        result += "L"
        robot_cord[1] -= 1
    elif robot_cord[1] < m - 1 and (grid[robot_cord[0]][robot_cord[1] + 1] == "*" or grid[robot_cord[0]][robot_cord[1] + 1] == "S") and (robot_cord[0] != prev[0] or robot_cord[1] + 1 != prev[1]):
        prev = [robot_cord[0], robot_cord[1]]
        result += "R"
        robot_cord[1] += 1
    if grid[robot_cord[0]][robot_cord[1]] == "S":
        break
print(result)