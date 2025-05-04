from collections import defaultdict, deque
n, m = map(int, input().split())
tree, result, queue, visited = defaultdict(list), 0, deque([1]), {1}
for _ in range(m):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)
while queue:
    brain = queue.popleft()
    last_brain = brain
    for i in tree[brain]:
        if i not in visited:
            visited.add(i)
            queue.append(i)
queue, visited = deque([(last_brain, 0)]), {last_brain}
while queue:
    brain, depth = queue.popleft()
    result = depth
    for i in tree[brain]:
        if i not in visited:
            visited.add(i)
            queue.append((i, depth + 1))
print(result)