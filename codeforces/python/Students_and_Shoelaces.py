from collections import defaultdict
n, m = map(int, input().split())
graph, removed_groups = defaultdict(set), 0
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].add(b)
    graph[b].add(a)
while True:
    leaves = set(())
    for i in graph:
        if len(graph[i]) == 1:
            leaves.add(i)
    if not leaves:
        break
    removed_groups += 1
    for i in leaves:
        if len(graph[i]) == 1:
            x = next(iter(graph[i]))
            del graph[i]
            if len(graph[x]) == 1:
                del graph[x]
            else:
                graph[x].remove(i)
print(removed_groups)