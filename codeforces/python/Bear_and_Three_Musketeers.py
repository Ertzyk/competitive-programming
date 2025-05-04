from collections import defaultdict

def solve():
    result = -1
    for i in range(1, n + 1):
        for j in graph[i]:
            if j > i:
                a = set(graph[i])&set(graph[j])
                for k in a:
                    s = len(graph[i]) + len(graph[j]) + len(graph[k]) - 6
                    result = s if result == -1 else min(result, s)
                    if result == 0:
                        return 0
    return result

n, m = map(int, input().split())
graph = defaultdict(list)
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
print(solve())