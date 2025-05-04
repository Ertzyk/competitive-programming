n, k, d = map(int, input().split())
comb_without_lim, cur = [1] + [2**i%(10**9 + 7) for i in range(min(k, n))], (2**k - 1)%(10**9 + 7)
for _ in range(n - k):
    comb_without_lim.append(cur)
    cur *= 2
    cur -= comb_without_lim[- k - 1]
    cur %= 10**9 + 7
if d == 1:
    print(comb_without_lim[n])
else:
    comb_with_lim = [0]*d + [1]
    for i in range(n - d):
        s1 = sum(comb_with_lim[-d + 1:])
        s2 = sum(comb_without_lim[max(0, len(comb_with_lim) - k): len(comb_with_lim) - d + 1])
        comb_with_lim.append((s1 + s2)%(10**9 + 7))
    print(comb_with_lim[n])