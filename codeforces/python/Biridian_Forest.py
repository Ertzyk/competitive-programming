from collections import deque
r, c = map(int, input().split())
grid, end_position = [], (-1, -1)
for i in range(r):
    row = input()
    grid.append(row)
    k = row.find("E")
    if k != -1:
        end_position = (i, k, 0)
queue, visited, directions, result, ending_depth = deque([end_position]), {(end_position[0], end_position[1])}, [(1, 0), (-1, 0), (0, 1), (0, -1)], 0, -1
while queue:
    x, y, depth = queue.popleft()
    if grid[x][y] == "S":
        ending_depth = depth
    elif grid[x][y].isdigit():
        if ending_depth == -1 or depth == ending_depth:
            result += int(grid[x][y])
        else:
            break
    for dir_x, dir_y in directions:
        if 0 <= x + dir_x < r and 0 <= y + dir_y < c and (x + dir_x, y + dir_y) not in visited and grid[x + dir_x][y + dir_y] != "T":
            queue.append((x + dir_x, y + dir_y, depth + 1))
            visited.add((x + dir_x, y + dir_y))
print(result)