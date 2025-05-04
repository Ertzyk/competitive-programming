from collections import defaultdict, deque
n, m = map(int, input().split())
graph, color = defaultdict(list), [-1]*(n + 1)
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
for i in range(1, n + 1):
    if color[i] == -1:
        queue, color[i] = deque([i]), 0
        while queue:
            vertex = queue.popleft()
            for i in graph[vertex]:
                if color[i] == -1:
                    color[i] = (color[vertex] + 1)%2
                    queue.append(i)
                else:
                    if color[i] == color[vertex]:
                        print(-1)
                        break
            else:
                continue
            break
        else:
            continue
        break
else:
    result1, result2 = [], []
    for i in range(1, n + 1):
        if color[i] == 0:
            result1.append(i)
        else:
            result2.append(i)
    print(len(result1))
    print(*result1)
    print(len(result2))
    print(*result2)