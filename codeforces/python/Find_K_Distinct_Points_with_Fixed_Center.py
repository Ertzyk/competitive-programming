t = int(input())
for _ in range(t):
    xc, yc, k = list(map(int, input().split()))
    if k == 1:
        print(" ".join(map(str, [xc, yc])))
    else:
        points = []
        if k%2:
            for i in range(k//2):
                points.append((i+1+xc, -1+yc))
                points.append((-i-1+xc, -1+yc))
        else:
            for i in range(k//2-1):
                points.append((i + 1 + xc, -1+yc))
                points.append((-i - 1 + xc, -1+yc))
            points.append((0 + xc, -1+yc))
        points.append((0 + xc, k - 1+yc))
        for i in points:
            print(" ".join(map(str, i)))