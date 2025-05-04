def find_permutation(a):
    if a == 5:
        return [2, 1, 3, 4, 5]
    elif a%2 == 0 and a & (a - 1) != 0:
        p, b = 0, a
        while b > 1:
            b = b >> 1
            p += 1
        return [i for i in range(1, 2**p - 1)] + [i for i in range(2**p + 1, a + 1)] + [2**p, 2**p - 1]
    else:
        return find_permutation(a - 1) + [a]

for _ in range(int(input())):
    n = int(input())
    if n%2:
        print(n)
    else:
        g, h = 0, n
        while h > 0:
            h = h >> 1
            g += 1
        print(2**g - 1)
    print(*find_permutation(n))