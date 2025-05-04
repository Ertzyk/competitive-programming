import math
from collections import defaultdict

def extended_euclid_algorithm(a, b):
    if b == 0:
        return a, 1, 0
    d, x, y = extended_euclid_algorithm(b, a%b)
    return d, y, x - (a//b)*y

def inverse_modulo(a, m):
    p, q, r = extended_euclid_algorithm(a, m)
    return q%m

n = int(input())
sum_k, count_presents = 0, defaultdict(int)
for _ in range(n):
    b = list(map(int, input().split()))
    k = b[0]
    a = b[1:]
    sum_k += k
    for i in a:
        count_presents[i] += 1
sum_k *= n
A = sum(map(lambda x: x**2, count_presents.values()))
print(sum_k, A)
x = math.gcd(sum_k, A)
sum_k //= x
A //= x
print(A*inverse_modulo(sum_k, 998244353)%998244353)
for A in range(1, 50):
    for sum_k in range(A + 1, 50):
        x = A*inverse_modulo(sum_k, 998244353)%998244353
        if x == 798595483:
            print(A, sum_k)
            print(x)