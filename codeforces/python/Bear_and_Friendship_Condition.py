from collections import defaultdict, deque

def solve():
    visited = set(())
    for i in range(1, n + 1):
        if i not in visited:
            visited.add(i)
            queue, degree, num_of_processed_nodes = deque([i]), len(graph[i]), 0
            while queue:
                node = queue.popleft()
                num_of_processed_nodes += 1
                if len(graph[node]) != degree:
                    return "NO"
                for j in graph[node]:
                    if j not in visited:
                        visited.add(j)
                        queue.append(j)
            if num_of_processed_nodes != degree + 1:
                return "NO"
    return "YES"
n, m = map(int, input().split())
graph = defaultdict(list)
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
print(solve())