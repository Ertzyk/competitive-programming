from collections import defaultdict
n, m = map(int, input().split())
graph, visited, result = defaultdict(list), {1}, [1]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
cur_possibilities = set(graph[1]) - {1}
while cur_possibilities:
    next_visit = min(cur_possibilities)
    result.append(next_visit)
    cur_possibilities.remove(next_visit)
    if len(cur_possibilities) < n - len(result):
        visited.add(next_visit)
        cur_possibilities |= set(graph[next_visit]) - visited
print(*result)