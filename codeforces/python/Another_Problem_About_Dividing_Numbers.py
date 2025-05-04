import math
sieve, primes = [False, False] + [True]*31620, []
for i in range(2, math.floor(31621**0.5) + 1):
    if sieve[i]:
        for j in range(i*i, 31622, i):
            sieve[j] = False
for i in range(31622):
    if sieve[i]:
        primes.append(i)
for _ in range(int(input())):
    a, b, k = map(int, input().split())
    min_lim, max_lim = 1 if (a%b == 0 or b%a == 0) and a != b else 2, 0
    for prime in primes:
        while a%prime == 0:
            a //= prime
            max_lim += 1
        if prime*prime > a:
            break
    if a > 1:
        max_lim += 1
    for prime in primes:
        while b%prime == 0:
            b //= prime
            max_lim += 1
        if prime*prime > b:
            break
    if b > 1:
        max_lim += 1
    print("YES" if min_lim <= k <= max_lim else "NO")