t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    result = 0
    while l != r:
        result += r - l
        l //= 10
        r //= 10
    print(result)