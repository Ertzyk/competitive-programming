for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = a[0]
    for i in range(n - 1):
        if d > a[i + 1]:
            print("NO")
            break
        d = a[i + 1] - d
    else:
        print("YES")