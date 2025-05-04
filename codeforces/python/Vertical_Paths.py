from collections import defaultdict

for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    tree, paths, root, order, path = defaultdict(list), [], -1, [], []
    for i in range(n):
        if i + 1 != p[i]:
            tree[p[i]].append(i + 1)
            tree[i + 1].append(p[i])
        else:
            root = i + 1
    stack = [(root, root)]
    while stack:
        node, parent = stack.pop()
        order.append((node, parent))
        for child in tree[node]:
            if child != parent:
                stack.append((child, node))
    order = order[::-1]
    for i in range(n):
        path.append(order[i][0])
        if i == n - 1 or order[i][1] != order[i + 1][0]:
            paths.append(path[::-1])
            path = []
    print(len(paths))
    for path in paths:
        print(len(path))
        print(*path)
    print()