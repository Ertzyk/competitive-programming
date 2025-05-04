for _ in range(int(input())):
    n, k = map(int, input().split())
    result = [1]*(k - 3)
    if (n - k)%2 == 0:
        result += [1, (n - k)//2 + 1, (n - k)//2 + 1]
    else:
        if (n - k)%4 == 3:
            result += [2, (n - k + 1)//2, (n - k + 1)//2]
        else:
            result += [(n - k + 3)//4, (n - k + 3)//4, (n - k + 1)//2 + 1]
    print(*result)