from collections import Counter
n, I = map(int, input().split())
a = list(map(int, input().split()))
K, c, disk, p = 2**(I*8//n), Counter(a), [], 0
for i in sorted(c.keys()):
    disk.append(c[i])
max_value = sum(disk[:K])
cur = max_value
while p + K < len(disk):
    cur -= disk[p]
    cur += disk[p + K]
    p += 1
    max_value = max(cur, max_value)
print(sum(disk) - max_value)


