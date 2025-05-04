from collections import defaultdict, deque
n, m = map(int, input().split())
graph, visited, result = defaultdict(list), set(()), 0
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
for i in range(1, n + 1):
    if i not in visited:
        visited.add(i)
        is_cyclic, queue = True, deque([i])
        while queue:
            vertex = queue.popleft()
            if len(graph[vertex]) != 2:
                is_cyclic = False
            for j in graph[vertex]:
                if j not in visited:
                    queue.append(j)
                    visited.add(j)
        if is_cyclic:
            result += 1
print(result)