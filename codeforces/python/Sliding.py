t = int(input())
for _ in range(t):
    n, m, r, c = map(int, input().split())
    print(2*m*n - 2*r*m + m - c - n + r)