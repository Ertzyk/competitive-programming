from collections import defaultdict
from itertools import combinations
for _ in range(int(input())):
    n = int(input())
    graph, connections, comb, stack, circuit, result = defaultdict(list), {}, list(combinations(range(n), 2)), [0], [], []
    for i in range(n):
        connections[i] = [0]*n
    for u, v in comb:
        graph[u].append(v)
        graph[v].append(u)
    if n%2 == 0:
        for i in range(0, n, 2):
            graph[i].remove(i + 1)
            graph[i + 1].remove(i)
    while stack:
        u = stack[-1]
        if graph[u]:
            v = graph[u][0]
            stack.append(v)
            graph[u].remove(v)
            graph[v].remove(u)
        else:
            circuit.append(stack.pop())
    for i in range(len(circuit) - 1):
        connections[circuit[i]][circuit[i + 1]] = 1
        connections[circuit[i + 1]][circuit[i]] = -1
    for u, v in comb:
        result.append(connections[u][v])
    print(*result)