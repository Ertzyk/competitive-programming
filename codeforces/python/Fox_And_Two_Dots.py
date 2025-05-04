from collections import deque

def solve():
    visited, directions = set(()), [[0, 1], [0, -1], [1, 0], [-1, 0]]
    for r in range(n):
        for c in range(m):
            if (r, c) not in visited:
                visited.add((r, c))
                queue = deque([(r, c, -1, -1)])
                while queue:
                    cord_r, cord_c, parent_r, parent_c = queue.popleft()
                    for dir_r, dir_c in directions:
                        if 0 <= cord_r + dir_r < n and 0 <= cord_c + dir_c < m and (cord_r + dir_r != parent_r or cord_c + dir_c != parent_c) and grid[cord_r + dir_r][cord_c + dir_c] == grid[cord_r][cord_c]:
                            if (cord_r + dir_r, cord_c + dir_c) in visited:
                                return "Yes"
                            visited.add((cord_r + dir_r, cord_c + dir_c))
                            queue.append((cord_r + dir_r, cord_c + dir_c, cord_r, cord_c))
    return "No"
n, m = map(int, input().split())
grid = [input() for _ in range(n)]
print(solve())