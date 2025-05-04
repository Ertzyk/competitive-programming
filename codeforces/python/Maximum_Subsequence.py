n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
hashset = {0}
for i in a:
    copy = hashset.copy()
    for j in copy:
        x = (i+j)%m
        if x == m - 1:
            print(m-1)
            break
        hashset.add(x)
    else:
        continue
    break
else:
    print(max(hashset))