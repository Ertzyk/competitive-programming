from collections import Counter
t = int(input())
for i in range(t):
    n = int(input())
    a = Counter(list(map(int, input().split())))
    s = 0
    for j in a.values():
        s += j//2
    print(s)