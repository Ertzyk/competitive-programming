t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    adjecent_to_missing = set(())
    m = 0
    for i in range(n):
        if a[i] == -1:
            if i > 0 and a[i-1] != -1:
                adjecent_to_missing.add(a[i-1])
            if i < n - 1 and a[i+1] != -1:
                adjecent_to_missing.add(a[i+1])
        if i == 0:
            continue
        if a[i] != -1 and a[i-1] != -1:
            m = max(m, abs(a[i]-a[i-1]))
    if not adjecent_to_missing:
        print(0, 42)
    else:
        d = max(adjecent_to_missing)
        k = (d + min(adjecent_to_missing))//2
        m = max(m, d - k)
        print(m, k)