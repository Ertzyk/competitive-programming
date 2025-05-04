from collections import defaultdict, deque
n, m = map(int, input().split())
c = list(map(int, input().split()))
graph, visited, result = defaultdict(list), set(()), 0
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
for i in range(1, n + 1):
    if i not in visited:
        visited.add(i)
        cur_min, queue = float('inf'), deque([i])
        while queue:
            a = queue.popleft()
            cur_min = min(cur_min, c[a - 1])
            for y in graph[a]:
                if y not in visited:
                    visited.add(y)
                    queue.append(y)
        result += cur_min
print(result)