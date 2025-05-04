from collections import defaultdict, deque
n = int(input())
p = [0, 0] + list(map(int, input().split()))
s = [0] + list(map(int, input().split()))
tree, a, queue = defaultdict(list), [0]*(n + 1), deque([1])
for i in range(2, n + 1):
    tree[i].append(p[i])
    tree[p[i]].append(i)
while queue:
    node = queue.popleft()
    if s[node] == -1:
        min_val = float('inf')
        for child in tree[node]:
            if child != p[node] and s[child] < min_val:
                min_val = s[child]
        if min_val != float('inf'):
            a[node], s[node] = min_val - s[p[node]], min_val
            if a[node] < 0:
                print(-1)
                break
    else:
        a[node] = s[node] - s[p[node]]
        if a[node] < 0:
            print(-1)
            break
    for child in tree[node]:
        if child != p[node]:
            queue.append(child)
else:
    print(sum(a))