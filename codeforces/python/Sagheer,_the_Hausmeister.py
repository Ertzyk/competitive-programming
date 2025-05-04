n, m = map(int, input().split())
building = []
for i in range(n):
    x = input()
    c, d = x.find("1"), m + 1 - x[::-1].find("1")
    if c != -1:
        building.append((c, d, n - i - 1))
if len(building) > 1:
    L, R = 0, 0
    for i in range(len(building) - 2):
        h = building[i][2] - building[i+1][2]
        L, R = min(building[i+1][0]+building[i][1]+h+R, 2*m-building[i+1][0]+2-building[i][0]+h+L), min(building[i+1][1]+building[i][1]+h+R, 2*m-building[i+1][1]+2-building[i][0]+h+L)
    print(min(building[-1][1]+building[-2][1]+building[-2][2]+R, 2*m-building[-1][1]+2-building[-2][0]+building[-2][2]+L)+building[-1][1])
elif len(building) == 1:
    print(building[0][1]+building[0][2])
else:
    print(0)