for _ in range(int(input())):
    n, m = map(int, input().split())
    attachment = [None]*n*m
    for i in range(1, n + 1):
        line = list(map(int, input().split()))
        for j in line:
            attachment[j] = i
    core = attachment[:n]
    for i in range(n, n*m, n):
        if core != attachment[i:i + n]:
            print(-1)
            break
    else:
        print(*core)