t = int(input())
for i in range(t):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    print(a[n//2])