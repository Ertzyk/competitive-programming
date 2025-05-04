from collections import defaultdict
for _ in range(int(input())):
    n, m = map(int, input().split())
    graph, leaves = defaultdict(list), 0
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    for i in graph:
        if len(graph[i]) == 1:
            leaves += 1
    print(m - leaves, leaves//(m - leaves))