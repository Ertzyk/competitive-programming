import math

def exp_degree(num, d):
    r = 0
    while num%d == 0:
        r += 1
        num //= d
    return r

n = int(input())
a = list(map(int, input().split()))
d, divisors, k, result = math.lcm(a[0], a[1]), [], 2, 1
while d > 1:
    if d%k == 0:
        divisors.append(k)
        d //= k
        while d%k == 0:
            d //= k
    k += 1
for div in divisors:
    first_min, second_min = exp_degree(a[0], div), 20
    for i in range(1, n):
        x = exp_degree(a[i], div)
        if x < first_min:
            first_min, second_min = x, first_min
        elif x < second_min:
            second_min = x
        if second_min == 0:
            break
    result *= div**second_min
print(result)