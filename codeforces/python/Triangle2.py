import math

def euclid(a, b):
    if b == 0:
        return a
    return euclid(b, a%b)
a, b = map(int, input().split())
if a < b:
    a, b = b, a
z = euclid(a, b)
if z == 1:
    print("NO")
else:
    i = 1
    while z**2 - i**2 > 0:
        x = z**2 - i**2
        if math.floor(x**0.5)**2 == x:
            print("YES")
            print(0, 0)
            print(i * (a // z), math.floor(x ** 0.5) * (a // z))
            if i * (a // z) == math.floor(x ** 0.5) * (b // z):
                print(i * (a // z) + math.floor(x ** 0.5) * (b // z), math.floor(x ** 0.5) * (a // z) - i * (b // z))
            else:
                print(i * (a // z) - math.floor(x ** 0.5) * (b // z), math.floor(x ** 0.5) * (a // z) + i * (b // z))
            break
        i += 1
    else:
        print("NO")