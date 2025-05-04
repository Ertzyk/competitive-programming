for _ in range(int(input())):
    n = int(input())
    kingdoms, daughters = {i + 1 for i in range(n)}, set(())
    for j in range(n):
        x = list(map(int, input().split()))
        k, g = x[0], x[1:]
        for i in g:
            if i in kingdoms:
                kingdoms.remove(i)
                break
        else:
            daughters.add(j + 1)
    print(f"IMPROVE\n{next(iter(daughters))} {next(iter(kingdoms))}" if kingdoms else "OPTIMAL")