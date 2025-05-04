for _ in range(int(input())):
    n = int(input())
    if n == 2:
        print("1 1\n2 1")
    elif n == 3:
        print("1 1\n2 1\n2 3")
    else:
        print("1 1\n2 1\n2 4")
        for i in range(4, n + 1):
            print(i, i)
    print()