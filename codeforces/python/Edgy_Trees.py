from collections import defaultdict, deque
n, k = map(int, input().split())
tree, visited, sizes = defaultdict(list), set(()), []
for _ in range(n - 1):
    u, v, x = map(int, input().split())
    if x == 0:
        tree[u].append(v)
        tree[v].append(u)
for i in range(1, n + 1):
    if i not in visited:
        visited.add(i)
        queue, size = deque([i]), 0
        while queue:
            node = queue.popleft()
            size += 1
            for i in tree[node]:
                if i not in visited:
                    queue.append(i)
                    visited.add(i)
        sizes.append(size)
print((pow(n, k, 10**9 + 7) - sum(map(lambda x: pow(x, k, 10**9 + 7), sizes)))%(10**9+7))