import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n, points_v, points_h, points_d1, points_d2 = int(input()), [], [], [], []
    res = 0
    for i in range(n):
        x, y = map(int, input().split())
        points_v.append(x)
        points_h.append(y)
        points_d1.append(x - y)
        points_d2.append(x + y)
    points_v.sort()
    points_h.sort()
    points_d1.sort()
    points_d2.sort()
    for p in [points_v, points_h, points_d1, points_d2]:
        prev, c = "", 0
        for i in p:
            if prev != i:
                res += c * (c - 1)
                prev = i
                c = 1
            else:
                c += 1
        res += c * (c - 1)
    print(res)