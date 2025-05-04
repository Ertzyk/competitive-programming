from collections import defaultdict, deque
n = int(input())
p = list(map(int, input().split()))
tree, unvisited, k = defaultdict(list), {i + 1 for i in range(n)}, 0
for i in range(n):
    tree[i + 1].append(p[i])
    tree[p[i]].append(i + 1)
while unvisited:
    x = next(iter(unvisited))
    unvisited.remove(x)
    queue = deque([x])
    while queue:
        a = queue.popleft()
        for i in tree[a]:
            if i in unvisited:
                unvisited.remove(i)
                queue.append(i)
    k += 1
print(k)