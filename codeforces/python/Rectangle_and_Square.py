def if_square(a, b, c, d):
    m1, m2 = ((a[0] + b[0]) / 2, (a[1] + b[1]) / 2), ((c[0] + d[0]) / 2, (c[1] + d[1]) / 2)
    if m1 == m2:
        return check_equal_lengths(m1, a, b, c, d) and (a[0] - c[0])**2 + (a[1] - c[1])**2 == (a[0] - d[0])**2 + (a[1] - d[1])**2
    else:
        m1, m2 = ((b[0] + c[0]) / 2, (b[1] + c[1]) / 2), ((a[0] + d[0]) / 2, (a[1] + d[1]) / 2)
        if m1 == m2:
            return check_equal_lengths(m1, a, b, c, d) and (a[0] - b[0])**2 + (a[1] - b[1])**2 == (a[0] - c[0])**2 + (a[1] - c[1])**2
        else:
            m1, m2 = ((a[0] + c[0]) / 2, (a[1] + c[1]) / 2), ((b[0] + d[0]) / 2, (b[1] + d[1]) / 2)
            return m1 == m2 and check_equal_lengths(m1, a, b, c, d) and (a[0] - b[0])**2 + (a[1] - b[1])**2 == (a[0] - d[0])**2 + (a[1] - d[1])**2

def if_rectangle(a, b, c, d):
    m1, m2 = ((a[0] + b[0]) / 2, (a[1] + b[1]) / 2), ((c[0] + d[0]) / 2, (c[1] + d[1]) / 2)
    if m1 == m2:
        return check_equal_lengths(m1, a, b, c, d)
    m1, m2 = ((b[0] + c[0]) / 2, (b[1] + c[1]) / 2), ((a[0] + d[0]) / 2, (a[1] + d[1]) / 2)
    if m1 == m2:
        return check_equal_lengths(m1, a, b, c, d)
    m1, m2 = ((a[0] + c[0]) / 2, (a[1] + c[1]) / 2), ((b[0] + d[0]) / 2, (b[1] + d[1]) / 2)
    return m1 == m2 and check_equal_lengths(m1, a, b, c, d)

def check_equal_lengths(m, a, b, c, d):
    x = (m[0] - a[0]) ** 2 + (m[1] - a[1]) ** 2
    for k in [b, c, d]:
        if (m[0] - k[0]) ** 2 + (m[1] - k[1]) ** 2 != x:
            return False
    else:
        return True

points = []
for i in range(8):
    points.append(tuple(map(int, input().split())))
for i1 in range(8):
    for i2 in range(i1 + 1, 8):
        for i3 in range(i2 + 1, 8):
            for i4 in range(i3 + 1, 8):
                if if_square(points[i1], points[i2], points[i3], points[i4]):
                    point_nums = {i for i in range(8)}
                    point_nums.remove(i1)
                    point_nums.remove(i2)
                    point_nums.remove(i3)
                    point_nums.remove(i4)
                    j1, j2, j3, j4 = point_nums
                    if if_rectangle(points[j1], points[j2], points[j3], points[j4]):
                        print("YES")
                        print(*[i1 + 1, i2 + 1, i3 + 1, i4 + 1])
                        print(*[j1 + 1, j2 + 1, j3 + 1, j4 + 1])
                        break
            else:
                continue
            break
        else:
            continue
        break
    else:
        continue
    break
else:
    print("NO")