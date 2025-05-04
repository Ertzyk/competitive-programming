from collections import defaultdict, deque
n, m = map(int, input().split())
graph = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
if n - 1 != m:
    print("no")
else:
    not_visited, queue = {i + 1 for i in range(n)}, deque([1])
    while queue:
        brain = queue.popleft()
        for i in graph[brain]:
            if i in not_visited:
                not_visited.remove(i)
                queue.append(i)
    print("no" if not_visited else "yes")