from collections import deque
n, m = map(int, input().split())
labyrinth = []
for i in range(n):
    x = input()
    labyrinth.append(x)
    a, b = x.find("A"), x.find("B")
    if a != -1:
        start = (i, a)
    if b != -1:
        end = (i, b)
queue, visited, directions = deque([(start, 0, "")]), {start}, [(-1, 0), (0, 1), (1, 0), (0, -1)]
while queue:
    cord, depth, path = queue.popleft()
    cord_x, cord_y = cord
    for dir_x, dir_y in directions:
        if 0 <= cord_x + dir_x < n and 0 <= cord_y + dir_y < m and labyrinth[cord_x + dir_x][cord_y + dir_y] == "B":
            print(f"YES\n{depth + 1}\n{path + ("L" if (dir_x, dir_y) == (0, -1) else "R" if (dir_x, dir_y) == (0, 1) else "U" if (dir_x, dir_y) == (-1, 0) else "D")}")
            break
        if 0 <= cord_x + dir_x < n and 0 <= cord_y + dir_y < m and labyrinth[cord_x + dir_x][cord_y + dir_y] != "#" and (cord_x + dir_x, cord_y + dir_y) not in visited:
            visited.add((cord_x + dir_x, cord_y + dir_y))
            queue.append(((cord_x + dir_x, cord_y + dir_y), depth + 1, path + ("L" if (dir_x, dir_y) == (0, -1) else "R" if (dir_x, dir_y) == (0, 1) else "U" if (dir_x, dir_y) == (-1, 0) else "D")))
    else:
        continue
    break
else:
    print("NO")