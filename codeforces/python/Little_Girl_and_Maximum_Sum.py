n, q = list(map(int, input().split()))
a = list(map(int, input().split()))
count, result, cur = [0]*n, 0, 0
for _ in range(q):
    l, r = map(int, input().split())
    count[l-1] += 1
    if r < n:
        count[r] -= 1
for i in range(n):
    cur += count[i]
    count[i] = cur
a.sort()
count.sort()
for i in range(n):
    result += count[i]*a[i]
print(result)