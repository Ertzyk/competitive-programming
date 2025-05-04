from collections import deque
for _ in range(int(input())):
    n, m = map(int, input().split())
    grid, directions, good_cords = [], [(-1, 0), (0, -1), (1, 0), (0, 1)], set(())
    for _ in range(n):
        grid.append(list(input()))
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "B":
                grid[i][j] = "#"
                for dir_r, dir_c in directions:
                    if 0 <= i + dir_r < n and 0 <= j + dir_c < m:
                        if grid[i + dir_r][j + dir_c] == ".":
                            grid[i + dir_r][j + dir_c] = "#"
                        elif grid[i + dir_r][j + dir_c] == "G":
                            print("No")
                            break
                else:
                    continue
                break
            elif grid[i][j] == "G":
                good_cords.add((i, j))
        else:
            continue
        break
    else:
        if grid[n - 1][m - 1] == "#":
            print("No" if good_cords else "Yes")
        else:
            queue, visited = deque([(n - 1, m - 1)]), {(n - 1, m - 1)}
            while queue:
                x, y = queue.popleft()
                for dir_r, dir_c in directions:
                    if 0 <= x + dir_r < n and 0 <= y + dir_c < m and grid[x + dir_r][y + dir_c] != "#" and (x + dir_r, y + dir_c) not in visited:
                        queue.append((x + dir_r, y + dir_c))
                        visited.add((x + dir_r, y + dir_c))
            print("No" if good_cords - visited else "Yes")