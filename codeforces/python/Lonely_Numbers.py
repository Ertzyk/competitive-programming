import math
t = int(input())
n = list(map(int, input().split()))
a = max(n)
sieve = [False, False] + [True] * (a - 1)
for j in range(2, math.floor(a**0.5) + 1):
    if sieve[j]:
        for k in range(j**2, a + 1, j):
            sieve[k] = False
num_of_primes, cur = [], 0
for i in range(a + 1):
    cur += sieve[i]
    num_of_primes.append(cur)
for i in range(t):
    print(num_of_primes[n[i]] - num_of_primes[math.floor(n[i]**0.5)] + 1)