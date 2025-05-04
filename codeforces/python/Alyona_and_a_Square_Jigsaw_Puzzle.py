import math
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s, h_days = 0, 0
    for i in a:
        s += i
        if math.floor(math.sqrt(s))**2 == s and math.floor(math.sqrt(s))%2:
            h_days += 1
    print(h_days)