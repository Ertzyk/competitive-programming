from collections import defaultdict
n = int(input())
tree, result, left = defaultdict(list), [None]*(n - 1), {i for i in range(n - 1)}
for i in range(n - 1):
    u, v = map(int, input().split())
    tree[u].append((v, i))
    tree[v].append((u, i))
for i in range(n):
    if len(tree[i + 1]) >= 3:
        result[tree[i + 1][0][1]], result[tree[i + 1][1][1]], result[tree[i + 1][2][1]] = 0, 1, 2
        left.remove(0)
        left.remove(1)
        left.remove(2)
        break
for i in range(n - 1):
    if result[i] is None:
        num = next(iter(left))
        result[i] = num
        left.remove(num)
for i in result:
    print(i)