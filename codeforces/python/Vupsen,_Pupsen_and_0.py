from collections import Counter
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    c, res, start, key_to_delete, mem_index, mem_num = Counter(a), [], 0, [], -1, -1
    if n%2:
        res.append(2*a[1]*a[2])
        res.append(-a[0]*a[2])
        res.append(-a[0]*a[1])
        c[a[0]] -= 1
        c[a[1]] -= 1
        c[a[2]] -= 1
        start = 3
    for key in c:
        if c[key] < 2:
            key_to_delete.append(key)
        elif c[key]%2:
            c[key] -= 1
    for key in key_to_delete:
        del c[key]
    for i in range(start, n):
        if c[a[i]]:
            res.append(1 if c[a[i]]%2 else -1)
            c[a[i]] -= 1
            if c[a[i]] == 0:
                del c[a[i]]
        else:
            if mem_index == -1:
                mem_index, mem_num = i, a[i]
                res.append(0)
            else:
                res[mem_index] = a[i]
                res.append(-mem_num)
                mem_index = -1
    print(*res)