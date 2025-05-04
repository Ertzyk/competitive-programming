a, b, c = map(int, input().split())
if (a + b + c)%2:
    print("Impossible")
else:
    x1, x2, x3 = (a + b - c)//2, (-a + b + c)//2, (a - b + c)//2
    if x1 >= 0 and x2 >= 0 and x3 >= 0 and a + b > 0 and b + c > 0 and c + a > 0:
        print(x1, x2, x3)
    else:
        print("Impossible")
