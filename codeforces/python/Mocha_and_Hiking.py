for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if a[-1] == 0:
        print(*[i + 1 for i in range(n + 1)])
    else:
        for i in range(n - 1):
            if a[i] == 0 and a[i + 1] == 1:
                print(*[j + 1 for j in range(i + 1)] + [n + 1] + [j for j in range(i + 2, n + 1)])
                break
        else:
            print(*[n + 1] + [i + 1 for i in range(n)])