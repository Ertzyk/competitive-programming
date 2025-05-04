for _ in range(int(input())):
    n = int(input())
    if n == 2 or n == 3:
        print(-1)
    elif n == 4:
        print("2 4 1 3")
    else:
        if n%5 == 0:
            result = [2, 4, 1, 3, 5]
        elif n%5 == 1:
            result = [1, 4, 2, 5, 3, 6]
        elif n%5 == 2:
            result = [1, 5, 2, 4, 6, 3, 7]
        elif n%5 == 3:
            result = [1, 3, 7, 5, 2, 4, 6, 8]
        else:
            result = [2, 4, 1, 3, 6, 8, 5, 7, 9]
        for i in range(n//5 - 1):
            result.append(result[-1] + 3)
            result.append(result[-1] - 2)
            result.append(result[-1] + 3)
            result.append(result[-1] - 2)
            result.append(result[-1] + 3)
        print(*result)