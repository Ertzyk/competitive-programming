from collections import deque
grid, statues, queue, visited, max_height = [], [], deque([(7, 0, 0)]), {(7, 0, 0)}, 8
for i in range(8):
    row = input()
    for j in range(8):
        if row[j] == "S":
            statues.append((i, j))
            if i < 7:
                statues.append((i + 1, j))
            if max_height == 8:
                max_height = i
while queue:
    x, y, move = queue.popleft()
    if move == 8 - max_height:
        print("WIN")
        break
    for dir_x in [0, -1, 1]:
        for dir_y in [0, -1, 1]:
            if 0 <= x + dir_x < 8 and 0 <= y + dir_y < 8 and (x + dir_x, y + dir_y, move + 1) not in visited:
                for s_x, s_y in statues:
                    if x + dir_x == s_x + move and y + dir_y == s_y:
                        break
                else:
                    queue.append((x + dir_x, y + dir_y, move + 1))
                    visited.add((x + dir_x, y + dir_y, move + 1))
else:
    print("LOSE")