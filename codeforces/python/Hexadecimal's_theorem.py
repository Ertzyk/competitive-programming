n = int(input())
indexes = []
while len(indexes) < 3 and n > 0:
    a, b = 0, 1
    while b <= n:
        a, b = b, a + b
    indexes.append(a)
    n -= a
if n != 0:
    print("I'm too stupid to solve this problem")
else:
    while len(indexes) < 3:
        indexes.append(0)
    print(*indexes[::-1])