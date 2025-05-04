from collections import defaultdict, deque
n, m, k = map(int, input().split())
c = list(map(int, input().split()))
graph, sizes, visited = defaultdict(list), [], set(())
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
for i in c:
    queue = deque([i])
    visited.add(i)
    size = 0
    while queue:
        city = queue.popleft()
        size += 1
        for neighbor in graph[city]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)
    sizes.append(size)
max_size = max(sizes)
print(sum(map(lambda x: x*(x-1)//2, sizes)) - max_size*(max_size-1)//2 + (n - len(visited) + max_size)*(n - len(visited) + max_size-1)//2 - m)