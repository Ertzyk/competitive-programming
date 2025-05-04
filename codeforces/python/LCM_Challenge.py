n = int(input())
print(n if n < 3 else n*(n - 1)*(n - 2) if n%2 else n*(n - 1)*(n - 3) if n%3 else (n - 1)*(n - 2)*(n - 3))