def a_wins(n):
    if n == 2:
        return 1
    part_res = 1
    for i in range(n//2 + 1, n):
        part_res *= i
    for i in range(1, n//2):
        part_res //= i
    return (part_res + b_wins(n - 2))%998244353

def b_wins(n):
    if n == 2:
        return 0
    part_res = 1
    for i in range(n//2 + 1, n - 1):
        part_res *= i
    for i in range(1, n//2 - 1):
        part_res //= i
    return (part_res + a_wins(n - 2))%998244353

t = int(input())
for _ in range(t):
    n = int(input())
    print(" ".join(map(str, [a_wins(n)%998244353, b_wins(n)%998244353, 1])))