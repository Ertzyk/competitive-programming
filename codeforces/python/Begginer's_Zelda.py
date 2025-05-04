from collections import defaultdict
t = int(input())
for _ in range(t):
    n, tree, res = int(input()), defaultdict(list), 0
    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
    for i in tree:
        if len(tree[i]) == 1:
            res += 1
    print((res+1)//2)