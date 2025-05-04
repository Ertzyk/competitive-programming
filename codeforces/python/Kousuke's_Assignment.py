t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    cur, sums, result = 0, {0}, 0
    for i in a:
        cur += i
        if cur not in sums:
            sums.add(cur)
        else:
            result += 1
            sums.clear()
            cur, sums = 0, {0}
    print(result)