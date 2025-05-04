from collections import deque

for _ in range(int(input())):
    n, m = map(int, input().split())
    grid, result, visited = [], 0, [[False]*m for _ in range(n)]
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    for i in range(n):
        for j in range(m):
            if grid[i][j] > 0 and not visited[i][j]:
                volume, queue = 0, deque([(i, j)])
                visited[i][j] = True
                while queue:
                    x, y = queue.popleft()
                    volume += grid[x][y]
                    if x > 0 and grid[x - 1][y] > 0 and not visited[x - 1][y]:
                        queue.append((x - 1, y))
                        visited[x - 1][y] = True
                    if y > 0 and grid[x][y - 1] > 0 and not visited[x][y - 1]:
                        queue.append((x, y - 1))
                        visited[x][y - 1] = True
                    if x < n - 1 and grid[x + 1][y] > 0 and not visited[x + 1][y]:
                        queue.append((x + 1, y))
                        visited[x + 1][y] = True
                    if y < m - 1 and grid[x][y + 1] > 0 and not visited[x][y + 1]:
                        queue.append((x, y + 1))
                        visited[x][y + 1] = True
                result = max(result, volume)
    print(result)