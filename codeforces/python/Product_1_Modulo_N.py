def gcd(a, b):
    while b > 0:
        a, b = b, a%b
    return a

def is_prime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

n = int(input())
if n == 2:
    print(1)
    print(1)
elif is_prime(n):
    print(n-2)
    print(" ".join([str(i+1) for i in range(n-2)]))
else:
    relative_prime, product = [1], 1
    for i in range(2,n-1):
        if gcd(n, i) == 1:
            relative_prime.append(i)
            product *= i
            product %= n
    relative_prime.append(n - 1)
    product *= n - 1
    product %= n
    if product != 1:
        relative_prime.remove(product)
    print(len(relative_prime))
    print(" ".join(map(str, relative_prime)))