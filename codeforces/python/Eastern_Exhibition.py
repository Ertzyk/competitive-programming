t = int(input())
for _ in range(t):
    n, houses_x, houses_y = int(input()), [], []
    for _ in range(n):
        x, y = map(int, input().split())
        houses_x.append(x)
        houses_y.append(y)
    if len(houses_x)%2:
        x_comb, y_comb = 1, 1
    else:
        houses_x.sort()
        houses_y.sort()
        x_comb, y_comb = houses_x[len(houses_x)//2] - houses_x[len(houses_x)//2-1] + 1, houses_y[len(houses_y)//2] - houses_y[len(houses_y)//2-1] + 1
    print(x_comb * y_comb)