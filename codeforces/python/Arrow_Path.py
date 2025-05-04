from collections import deque
for _ in range(int(input())):
    n = int(input())
    grid = [input(), input()]
    queue, visited = deque([(1, 1)]), {(1, 1)}
    while queue:
        r, c = queue.popleft()
        if r == 2 and c == n:
            print("YES")
            break
        if (r + c)%2:
            if grid[r - 1][c - 1] == ">" and (r, c + 1) not in visited:
                queue.append((r, c + 1))
                visited.add((r, c + 1))
            elif grid[r - 1][c - 1] == "<" and (r, c - 1) not in visited:
                queue.append((r, c - 1))
                visited.add((r, c - 1))
        else:
            if r == 1 and (r + 1, c) not in visited:
                queue.append((r + 1, c))
                visited.add((r + 1, c))
            elif r == 2 and (r - 1, c) not in visited:
                queue.append((r - 1, c))
                visited.add((r - 1, c))
            if c > 1 and (r, c - 1) not in visited:
                queue.append((r, c - 1))
                visited.add((r, c - 1))
            if c < n and (r, c + 1) not in visited:
                queue.append((r, c + 1))
                visited.add((r, c + 1))
    else:
        print("NO")