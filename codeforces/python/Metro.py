from collections import defaultdict, deque
n, s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
graph = defaultdict(list)
stopped_at = set(())
for i in range(n):
    if a[i] == 1:
        for j in stopped_at:
            graph[j].append(i + 1)
        stopped_at.add(i + 1)
stopped_at = set(())
for i in range(n - 1, -1, -1):
    if b[i] == 1:
        for j in stopped_at:
            graph[j].append(i + 1)
        stopped_at.add(i + 1)
queue, visited = deque([1]), set()
while queue:
    station = queue.popleft()
    if station == s:
        print("YES")
        break
    for i in graph[station]:
        if i not in visited:
            visited.add(i)
            queue.append(i)
else:
    print("NO")