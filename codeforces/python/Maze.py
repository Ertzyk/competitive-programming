from collections import defaultdict, deque
n, m, k = map(int, input().split())
grid, start = [], (-1, -1)
for _ in range(n):
    row = list(input())
    grid.append(row)
for i in range(n):
    for j in range(m):
        if grid[i][j] == ".":
            start = (i, j)
            break
    else:
        continue
    break
if start == (-1, -1):
    for i in range(n):
        print("#"*m)
else:
    visited, queue, directions, spanning_tree, d = {start}, deque([start]), [(-1, 0), (1, 0), (0, -1), (0, 1)], defaultdict(list), 0
    while queue:
        x, y = queue.popleft()
        for r, c in directions:
            if 0 <= x + r < n and 0 <= y + c < m and grid[x + r][y + c] == "." and (x + r, y + c) not in visited:
                queue.append((x + r, y + c))
                visited.add((x + r, y + c))
                spanning_tree[(x + r, y + c)].append((x, y))
                spanning_tree[(x, y)].append((x + r, y + c))
    while d < k:
        for x, y in spanning_tree:
            if len(spanning_tree[(x, y)]) == 1:
                grid[x][y] = "X"
                d += 1
                spanning_tree[spanning_tree[(x, y)][0]].remove((x, y))
                del spanning_tree[(x, y)]
                break
    for i in range(n):
        print("".join(grid[i]))