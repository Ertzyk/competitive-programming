n = int(input())
sizes, l, r, result = [], 0, 1, n
for _ in range(n):
    sizes.append(int(input()))
sizes.sort(reverse=True)
print(sizes)
while r < n and sizes[0] < sizes[r]*2:
    r += 1
start = r

while r < n and l < start:
    if sizes[l] >= sizes[r]*2:
        print(sizes[l], l, sizes[r], r)
        result -= 1
        l += 1
    r += 1
print(result)