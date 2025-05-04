def fast_exponentiation(a, b):
    if b == 0:
        return 1
    if b%2:
        return a * fast_exponentiation(a, b - 1)
    return fast_exponentiation(a**2, b//2)

n = int(input())
print(3*(3*n - 1)*fast_exponentiation(4, n - 3))