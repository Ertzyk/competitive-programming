from collections import Counter
n = int(input())
a = list(map(int, input().split()))
c = sorted(Counter(a).values(), reverse=True)
result, l, r = 0, 0, len(c) - 1
while l <= r:
    result += 1
    s, cur = c[l], 0
    while cur + c[r] < s and l <= r:
        cur += c[r]
        r -= 1
    l += 1
print(result)