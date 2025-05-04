from collections import defaultdict
import sys
sys.setrecursionlimit(4000)

def dfs(tree, b_or_w, node):
    x, s = 1 if b_or_w[node - 1] == 'W' else -1, 0
    for i in tree[node]:
        c, d = dfs(tree, b_or_w, i)
        x += c
        s += d
    if x == 0:
        s += 1
    return x, s

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = input()
    tree, white_minus_black = defaultdict(list), [1]*(n+1)
    for i in range(n - 1):
        tree[a[i]].append(i + 2)
    p, q = dfs(tree, s, 1)
    print(q)