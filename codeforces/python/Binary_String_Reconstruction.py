for _ in range(int(input())):
    n0, n1, n2 = map(int, input().split())
    if n1 == 0:
        print("1"*(n2 + 1) if n2 > 0 else "0"*(n0 + 1))
    else:
        result = "1"*(n2 + 1) + "0"*(n0 + 1)
        for i in range(n1 - 1):
            result += str((i + 1)%2)
        print(result)
