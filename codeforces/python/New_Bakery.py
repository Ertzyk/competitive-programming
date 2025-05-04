t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    z, y = min(n, b), round(b-a+1/2)
    k = y if 0 <= y <= z else 0 if y < 0 else z
    print(k*(2*b - k + 1)//2 + a*(n-k))

