t = int(input())
for _ in range(t):
    n, m = list(map(int, input().split()))
    for i in range(n):
        row = []
        for j in range(m):
            row.append(int(((i%4 == 0 or i%4 == 3) and (j%4 == 1 or j%4 == 2)) or ((i%4 == 1 or i%4 == 2) and (j%4 == 0 or j%4 == 3))))
        print(" ".join(map(str, row)))