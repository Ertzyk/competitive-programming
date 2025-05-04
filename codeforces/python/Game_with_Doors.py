t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    L, R = map(int, input().split())
    k = 1
    for i in range(l,r+1):
        if L <= i <= R:
            k += 1
    if l == L:
        k -= 1
    if r == R:
        k -= 1
    print(k)