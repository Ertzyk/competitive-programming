for _ in range(int(input())):
    n, m = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    cord_1, cord_2 = (x1, y1), (x2, y2)
    if n == 2 or m == 2 or cord_1 == (1, 1) or cord_1 == (n, 1) or cord_1 == (1, m) or cord_1 == (n, m) or cord_2 == (1, 1) or cord_2 == (n, 1) or cord_2 == (1, m) or cord_2 == (n, m):
        print(2)
    elif n == 3 or m == 3 or cord_1[0] == 1 or cord_1[0] == n or cord_1[1] == 1 or cord_1[1] == m or cord_2[0] == 1 or cord_2[0] == n or cord_2[1] == 1 or cord_2[1] == m:
        print(3)
    else:
        print(4)