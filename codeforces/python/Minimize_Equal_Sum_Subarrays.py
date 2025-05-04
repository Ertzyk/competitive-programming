t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    print(" ".join(map(str, p[1:] + [p[0]])))