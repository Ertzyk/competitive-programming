from collections import deque
n, m = map(int, input().split())
grid, rooms, visited = [], 0, [[False]*m for _ in range(n)]
for _ in range(n):
    grid.append(list(input()))
for a in range(n):
    for b in range(m):
        if grid[a][b] == "." and not visited[a][b]:
            rooms += 1
            queue, visited[a][b] = deque([(a, b)]), True
            while queue:
                i, j = queue.popleft()
                if i > 0 and grid[i-1][j] == "." and not visited[i-1][j]:
                    queue.append((i-1, j))
                    visited[i - 1][j] = True
                if j > 0 and grid[i][j-1] == "." and not visited[i][j-1]:
                    queue.append((i, j-1))
                    visited[i][j - 1] = True
                if i < n - 1 and grid[i+1][j] == "." and not visited[i+1][j]:
                    queue.append((i+1, j))
                    visited[i + 1][j] = True
                if j < m - 1 and grid[i][j+1] == "." and not visited[i][j+1]:
                    queue.append((i, j+1))
                    visited[i][j + 1] = True
print(rooms)