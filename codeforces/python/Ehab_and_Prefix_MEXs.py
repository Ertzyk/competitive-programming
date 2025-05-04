n = int(input())
a = list(map(int, input().split()))
result, prev, used_nums, p = [-1]*n, 0, {a[-1]}, 0
for i in range(n):
    if a[i] != prev:
        result[i] = prev
        used_nums.add(prev)
    prev = a[i]
for i in range(n):
    if result[i] == -1:
        while True:
            if p not in used_nums:
                result[i] = p
                used_nums.add(p)
                break
            p += 1
print(*result)