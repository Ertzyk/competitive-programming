n = int(input())
left, result = {i for i in range(1, n + 1)}, ["!"] + [None] * n
while len(left) > 1:
    it = iter(left)
    p1 = next(it)
    p2 = next(it)
    print(f"? {p1} {p2}", flush = True)
    c1 = int(input())
    print(f"? {p2} {p1}", flush=True)
    c2 = int(input())
    if c1 > c2:
        result[p1] = c1
        left.remove(p1)
    else:
        result[p2] = c2
        left.remove(p2)
result[next(iter(left))] = n
print(*result)