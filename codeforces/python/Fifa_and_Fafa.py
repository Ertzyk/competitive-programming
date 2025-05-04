R, x1, y1, x2, y2 = map(int, input().split())
if (x2 - x1)**2 + (y2 - y1)**2 >= R**2:
    print(x1, y1, R)
elif x1 == x2 and y1 == y2:
    print(x1 + R/2, y1, R/2)
else:
    c = R/((x1 - x2)**2 + (y1 - y2)**2)**0.5
    m1, m2 = (x2 + c*x1 - c*x2 + x1)/2, (y2 + c*y1 - c*y2 + y1)/2
    print(m1, m2, ((m1 - x2)**2 + (m2 - y2)**2)**0.5)