n, t = map(int, input().split())
k = int(input())
l, r = 0, n - 1
while l <= r:
    m = (l + r)//2
    print(f"? {1} {m + 1}", flush = True)
    x = int(input())
    if m + 1 - x < k:
        l = m + 1
    else:
        result, r = m, m - 1
print(f"! {result + 1}")