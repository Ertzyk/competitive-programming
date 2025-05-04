from collections import defaultdict
for _ in range(int(input())):
    n = int(input())
    graph, result = defaultdict(list), [0]*n
    for i in range(n):
        row = input()
        result[row[:i].count("1") + row[i + 1:].count("0")] = i + 1
    print(*result)