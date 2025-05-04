import math
a, b, k = map(int, input().split())
sieve, result, l, r, num_of_primes, cur = [False, False] + [True]*(b - 1), -1, 1, b - a + 1, [0], 0
for i in range(2, math.floor(b**0.5) + 1):
    if sieve[i]:
        for j in range(i*i, b + 1, i):
            sieve[j] = False
for i in range(b - a + 1):
    cur += sieve[a + i]
    num_of_primes.append(cur)
while l <= r:
    m = (l + r)//2
    for x in range(1, b - a + 3 - m):
        if num_of_primes[x + m - 1] - num_of_primes[x - 1] < k:
            l = m + 1
            break
    else:
        result, r = m, m - 1
print(result)