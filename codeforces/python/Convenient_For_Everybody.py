n = int(input())
a = list(map(int, input().split()))
s, f = map(int, input().split())
s -= 1
f -= 2
cur_sum, res = sum(a[s:f + 1]), 1
max_sum = cur_sum
for i in range(n - 1):
    cur_sum -= a[f]
    f -= 1
    s -= 1
    cur_sum += a[s]
    if cur_sum > max_sum:
        max_sum, res = cur_sum, i + 2
print(res)