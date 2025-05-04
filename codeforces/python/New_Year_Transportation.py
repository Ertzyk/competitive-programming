n, t = map(int, input().split())
a = list(map(int, input().split()))
p = 0
while p < t:
    p += a[p]
    if p == t - 1:
        print("YES")
        break
else:
    print("NO")