def right_triangle(a, b, c):
    l_ab_sq = (a[0] - b[0])**2 + (a[1] - b[1])**2
    l_bc_sq = (b[0] - c[0])**2 + (b[1] - c[1])**2
    l_ac_sq = (a[0] - c[0])**2 + (a[1] - c[1])**2
    return ((l_ab_sq + l_bc_sq == l_ac_sq or
            l_bc_sq + l_ac_sq == l_ab_sq or
            l_ac_sq + l_ab_sq == l_bc_sq) and l_ab_sq and l_bc_sq and l_ac_sq)
x1, y1, x2, y2, x3, y3 = list(map(int, input().split()))
A, B, C = (x1, y1), (x2, y2), (x3, y3)
if right_triangle(A, B, C):
    print("RIGHT")
else:
    for i in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
        A2 = [A[0] + i[0], A[1] + i[1]]
        B2 = [B[0] + i[0], B[1] + i[1]]
        C2 = [C[0] + i[0], C[1] + i[1]]
        if right_triangle(A2, B, C) or right_triangle(A, B2, C) or right_triangle(A, B, C2):
            print("ALMOST")
            break
    else:
        print("NEITHER")