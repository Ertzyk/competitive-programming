from collections import defaultdict
n, k = map(int, input().split())
a = list(map(int, input().split()))
l, r, l_res, r_res, hashmap = 0, 0, 1, 1, defaultdict(int)
while r < len(a):
    hashmap[a[r]] += 1
    r += 1
    while len(hashmap.keys()) > k:
        hashmap[a[l]] -= 1
        if hashmap[a[l]] == 0:
            del hashmap[a[l]]
        l += 1
    if r - 1 - l > r_res - l_res:
        l_res, r_res = l + 1, r
print(l_res, r_res)