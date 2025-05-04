t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int, list(str(n))))
    y, s, k = [0]*len(x), sum(x)//2, 0
    for i in range(len(x)):
        p = min(s-k, x[i])
        y[i] += p
        x[i] -= p
        k += p
        if k == s:
            break
    print(int("".join(map(str, x))), int("".join(map(str, y))))
