from collections import defaultdict, deque
n = int(input())
graph, ith_interval = defaultdict(list), []
for _ in range(n):
    t, x, y = map(int, input().split())
    if t == 1:
        for i in range(len(ith_interval)):
            if ith_interval[i][0] < x < ith_interval[i][1] or ith_interval[i][0] < y < ith_interval[i][1]:
                graph[len(ith_interval) + 1].append(i + 1)
            if x < ith_interval[i][0] < y or x < ith_interval[i][1] < y:
                graph[i + 1].append(len(ith_interval) + 1)
        ith_interval.append((x, y))
    else:
        queue, visited = deque([x]), {x}
        while queue:
            interval = queue.popleft()
            if interval == y:
                print("YES")
                break
            for i in graph[interval]:
                if i not in visited:
                    visited.add(i)
                    queue.append(i)
        else:
            print("NO")