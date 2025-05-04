for _ in range(int(input())):
    n = int(input())
    s = list(map(lambda x: int(x) - 1, list(input())))
    c = {0: 1}
    cur = 0
    for i in range(n):
        cur += s[i]
        c[cur] = c.get(cur, 0) + 1
    print(sum(map(lambda x: x*(x - 1)//2, c.values())))