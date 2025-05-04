from collections import defaultdict

for _ in range(int(input())):
    n, tree = int(input()), defaultdict(list)
    leaves, stack, order = [0]*(n + 1), [(1, -1)], []
    for i in range(n - 1):
        u, v = map(int, input().split())
        tree[v].append(u)
        tree[u].append(v)
    while stack:
        node, parent = stack.pop()
        order.append((node, parent))
        for i in tree[node]:
            if i != parent:
                stack.append((i, node))
    order = order[::-1]
    for i, parent in order:
        if len(tree[i]) == 1 and parent != -1:
            leaves[i] = 1
        else:
            for j in tree[i]:
                if j != parent:
                    leaves[i] += leaves[j]
    for i in range(int(input())):
        x, y = map(int, input().split())
        print(leaves[x]*leaves[y])