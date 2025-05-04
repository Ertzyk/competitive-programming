for _ in range(int(input())):
    l, r = map(int, input().split())
    print(1 if l == 1 and r == 1 else r - l)