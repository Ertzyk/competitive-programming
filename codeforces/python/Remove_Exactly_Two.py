from collections import defaultdict
for _ in range(int(input())):
    n = int(input())
    tree = defaultdict(set)
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tree[u].add(v)
        tree[v].add(u)
    first_delete = max(tree, key = lambda x: len(tree[x]))
    print(first_delete)
    res = len(tree[first_delete]) - 1
    for i in tree[first_delete]:
        tree[i].remove(first_delete)
    del tree[first_delete]
    print(res + len(tree[max(tree, key = lambda x: len(tree[x]))]))