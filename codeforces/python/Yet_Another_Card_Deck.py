n, q = list(map(int, input().split()))
a = list(map(int, input().split()))
t = list(map(int, input().split()))
hashmap, result = {}, []
for i in range(n):
    if a[i] not in hashmap:
        hashmap[a[i]] = i + 1
for i in t:
    result.append(hashmap[i])
    for j in hashmap:
        if hashmap[j] < hashmap[i]:
            hashmap[j] += 1
    hashmap[i] = 1
print(" ".join(map(str, result)))