for _ in range(int(input())):
    n, k = map(int, input().split())
    print(2 if k%n else 0)
    result = [[0 for _ in range(n)] for _ in range(n)]
    count = 0
    while count < k:
        result[(count + count//n)%n][count%n] = 1
        count += 1
    for row in result:
        print(*row, sep = "")