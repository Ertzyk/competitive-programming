for _ in range(int(input())):
    n = int(input())
    if n == 6:
        print(1, 1, 2, 3, 1, 2)
    elif n == 7:
        print(1, 1, 2, 3, 1, 2, 2)
    elif n == 8:
        print(1, 1, 2, 3, 4, 1, 2, 2)
    elif n == 10:
        print(1, 1, 2, 3, 4, 5, 6, 1, 2, 2)
    else:
        res = [i + 1 for i in range((n + 2)//3 + (n + 2)%3)]
        for i in range((n - 1)//3, 0, -1):
            res.append(i)
            res.append(i)
        print(*res)