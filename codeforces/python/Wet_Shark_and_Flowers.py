import math
n, p = map(int, input().split())
div_in_interval, result = [], 0
for _ in range(n):
    l, r = map(int, input().split())
    div_in_interval.append((r - l - r//p + math.ceil(l/p))/(r - l + 1))
for i in range(n - 1):
    result += 1 - div_in_interval[i]*div_in_interval[i + 1]
result += 1 - div_in_interval[-1]*div_in_interval[0]
print(result*2000)