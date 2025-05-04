import math
for _ in range(int(input())):
    r = int(input())
    result = 0
    for y in range(1, r + 1):
        result += math.floor(math.sqrt((r + 1)**2 - y**2) - 1e-10) - math.ceil(math.sqrt(r**2 - y**2)) + 1
    print(result*4)