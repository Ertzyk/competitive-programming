s = input()
res, prev, l = 0, "B", 0
for i in s:
    if i != prev:
        res = max(l, res)
        prev = i
        l = 1
    else:
        l += 1
res = max(l, res)
print(res)