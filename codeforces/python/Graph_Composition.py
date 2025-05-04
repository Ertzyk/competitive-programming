from collections import defaultdict, deque
for _ in range(int(input())):
    n, m1, m2 = map(int, input().split())
    graph_f, graph_g = defaultdict(set), defaultdict(set)
    for _ in range(m1):
        u, v = map(int, input().split())
        graph_f[u].add(v)
        graph_f[v].add(u)
    for _ in range(m2):
        u, v = map(int, input().split())
        graph_g[u].add(v)
        graph_g[v].add(u)
    g_compositions, visited, res = [], set(()), m1
    for i in range(1, n + 1):
        if i not in visited:
            visited.add(i)
            queue, group = deque([i]), set(())
            while queue:
                node = queue.popleft()
                group.add(node)
                for j in graph_g[node]:
                    if j not in visited:
                        queue.append(j)
                        visited.add(j)
            g_compositions.append(group)
    for composition in g_compositions:
        visited, k = set(()), 0
        for i in composition:
            if i not in visited:
                visited.add(i)
                queue = deque([i])
                while queue:
                    node = queue.popleft()
                    for j in graph_f[node]:
                        if j in composition:
                            if j not in visited:
                                visited.add(j)
                                queue.append(j)
                            k += 1
                res += 1
        res -= k//2 + 1
    print(res)