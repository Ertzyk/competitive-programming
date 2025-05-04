n, m = map(int, input().split())
x = list(map(int, input().split()))
for _ in range(m):
    l, r = map(int, input().split())
y, result, num_to_index = sorted(x), [], {}
for i in range(n):
    num_to_index[y[i]] = i%2
for i in range(n):
    result.append(num_to_index[x[i]])
print(*result)