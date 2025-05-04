n = int(input())
a, b, k = 2, 3, 1
while True:
    if a <= n < b:
        print(k)
        break
    a, b = b, a + b
    k += 1