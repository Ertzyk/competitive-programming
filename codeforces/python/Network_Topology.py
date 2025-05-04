from collections import defaultdict, deque
n, m = map(int, input().split())
graph = defaultdict(list)
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
a = list(map(lambda x: len(x), graph.values()))
if a.count(2) == n - 2 and a.count(1) == 2:
    print("bus topology")
elif a.count(1) == n - 1 and a.count(n - 1) == 1:
    print("star topology")
elif a.count(2) == n:
    print("ring topology")
else:
    print("unknown topology")