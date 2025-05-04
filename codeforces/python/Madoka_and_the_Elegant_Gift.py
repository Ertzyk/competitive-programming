from collections import deque
for _ in range(int(input())):
    n, m = map(int, input().split())
    grid, visited = [], set(())
    for _ in range(n):
        grid.append(list(input()))
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "1" and (i, j) not in visited:
                visited.add((i, j))
                queue, max_rectangle_r, max_rectangle_c, min_rectangle_r, min_rectangle_c, size = deque([(i, j)]), i, j, i, j, 0
                while queue:
                    r, c = queue.popleft()
                    size += 1
                    if r > max_rectangle_r:
                        max_rectangle_r = r
                    elif r < min_rectangle_r:
                        min_rectangle_r = r
                    if c > max_rectangle_c:
                        max_rectangle_c = c
                    elif c < min_rectangle_c:
                        min_rectangle_c = c
                    if r > 0 and grid[r - 1][c] == "1" and (r - 1, c) not in visited:
                        queue.append((r - 1, c))
                        visited.add((r - 1, c))
                    if r < n - 1 and grid[r + 1][c] == "1" and (r + 1, c) not in visited:
                        queue.append((r + 1, c))
                        visited.add((r + 1, c))
                    if c > 0 and grid[r][c - 1] == "1" and (r, c - 1) not in visited:
                        queue.append((r, c - 1))
                        visited.add((r, c - 1))
                    if c < m - 1 and grid[r][c + 1] == "1" and (r, c + 1) not in visited:
                        queue.append((r, c + 1))
                        visited.add((r, c + 1))
                if (max_rectangle_r - min_rectangle_r + 1)*(max_rectangle_c - min_rectangle_c + 1) != size:
                    print("NO")
                    break
        else:
            continue
        break
    else:
        print("YES")