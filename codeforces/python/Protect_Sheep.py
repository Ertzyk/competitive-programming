R, C = map(int, input().split())
grid = []
for i in range(R):
    grid.append(list(input().replace(".", "D")))
for i in range(R):
    for j in range(C):
        if grid[i][j] == "S" and (i > 0 and grid[i-1][j] == "W" or i < R - 1 and grid[i+1][j] == "W" or j > 0 and grid[i][j-1] == "W" or j < C - 1 and grid[i][j+1] == "W"):
            print("No")
            break
    else:
        continue
    break
else:
    print("Yes")
    for i in range(R):
        print("".join(grid[i]))