from collections import defaultdict, deque
n = int(input())
tree, blue_vertices, red_vertices, queue = defaultdict(list), {1}, set(()), deque([1])
for _ in range(n - 1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)
while queue:
    node = queue.popleft()
    if node in red_vertices:
        for i in tree[node]:
            if i not in blue_vertices:
                blue_vertices.add(i)
                queue.append(i)
    else:
        for i in tree[node]:
            if i not in red_vertices:
                red_vertices.add(i)
                queue.append(i)
print(len(blue_vertices)*len(red_vertices)-n+1)