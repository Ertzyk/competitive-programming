from collections import defaultdict
n, m = list(map(int, input().split()))
hashmap_r, hashmap_c, res = defaultdict(list), defaultdict(list), 0
for k in range(n-1, -1, -1):
    row = list(map(int, input().split()))
    for l in range(len(row)):
        hashmap_r[row[l]].append(k)
        hashmap_c[row[l]].append(l)
for i in hashmap_r:
    x = len(hashmap_r[i])
    for j in range(x):
        res += hashmap_r[i][j]*(x - 1 - 2*j)
for i in hashmap_c:
    hashmap_c[i].sort(reverse = True)
    x = len(hashmap_c[i])
    for j in range(x):
        res += hashmap_c[i][j] * (x - 1 - 2 * j)
print(res)