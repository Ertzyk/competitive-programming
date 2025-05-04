n, k = list(map(int, input().split()))
print("NO" if k > (n**2+1)//2 else "YES")
if k <= (n**2+1)//2:
    grid, l = [[] for _ in range(n)], 0
    for i in range(n):
        for j in range(n):
            grid[i].append('L' if i % 2 + j % 2 != 1 and l < k else 'S')
            l += 1 if i % 2 + j % 2 != 1 and l < k else 0
    for i in grid:
        print(''.join(i))