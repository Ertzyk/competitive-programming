t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if len(a) == 1:
        print(0)
    else:
        result = 0
        for i in a:
            l, r, s = 0, 1, a[0] + a[1]
            while r < len(a):
                if i > s:
                    if r == len(a) - 1:
                        break
                    r += 1
                    s += a[r]
                elif i < s:
                    s -= a[l]
                    l += 1
                    if l == r:
                        if r == len(a) - 1:
                            break
                        r += 1
                        s += a[r]
                else:
                    result += 1
                    break
        print(result)