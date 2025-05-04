n = int(input())
a = list(map(int, input().split()))
s = sum(a)
if s%3:
    print(0)
else:
    i, cur1, result = 0, 0, 0
    while i < n - 2:
        cur1 += a[i]
        i += 1
        if cur1 == s // 3:
            j, cur2 = i, 0
            while j < n - 1:
                cur2 += a[j]
                j += 1
                if cur2 == s // 3:
                    result += 1
    print(result)