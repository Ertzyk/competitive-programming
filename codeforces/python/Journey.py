from collections import defaultdict
n = int(input())
tree, stack, order, exp_val = defaultdict(list), [(1, 0)], [], [0]*(n + 1)
for _ in range(n - 1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)
while stack:
    node, parent = stack.pop()
    order.append((node, parent))
    for i in tree[node]:
        if i != parent:
            stack.append((i, node))
order.reverse()
for node, parent in order:
    res, count_children = 0, 0
    for i in tree[node]:
        if i != parent:
            count_children += 1
            res += exp_val[i] + 1
    if count_children != 0:
        exp_val[node] = res/count_children
print(exp_val[1])