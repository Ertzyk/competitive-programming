from collections import deque
n = int(input())
graph, result, visited = {}, 0, set(())
for _ in range(n):
    x, y = map(int, input().split())
    graph[f"{x};{y}"] = []
    for i in graph:
        a, b = int(i.split(";")[0]), int(i.split(";")[1])
        if (a == x or b == y) and not (a == x and b == y):
            graph[i].append(f"{x};{y}")
            graph[f"{x};{y}"].append(f"{a};{b}")
for i in graph.keys():
    if i not in visited:
        result += 1
        visited.add(i)
        queue = deque([i])
        while queue:
            node = queue.popleft()
            for j in graph[node]:
                if j not in visited:
                    visited.add(j)
                    queue.append(j)
print(result - 1)