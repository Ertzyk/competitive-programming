from collections import Counter
n = int(input())
a = list(map(int, input().split()))

import time
import random
n = 300000
b = []
for i in range(n):
    b.append(random.randint(1, 100))
a = b
start = time.time()

c, result = Counter(a).values(), [0]*n
for i in c:
    for k in range(1, i + 1):
        result[k - 1] += i//k
for i in range(len(result)):
    if result[i] == 0:
        break
    result[i] *= i + 1
print(*result)

end = time.time()
print(end - start)