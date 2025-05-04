from collections import defaultdict, deque
n, m = map(int, input().split())
graph = defaultdict(list)
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
if n != m:
    print("NO")
else:
    visited, queue = {1}, deque([1])
    while queue:
        node = queue.popleft()
        for i in graph[node]:
            if i not in visited:
                visited.add(i)
                queue.append(i)
    print("FHTAGN!" if len(visited) == n else "NO")