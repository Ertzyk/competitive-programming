n = int(input())
result = [n]
while n != 1:
    n = 3*n + 1 if n%2 else n//2
    result.append(n)
print(*result)