from collections import defaultdict
import sys
sys.setrecursionlimit(2000)

def tree_height(tree, root):
    max_h = 0
    for i in tree[root]:
        max_h = max(max_h, tree_height(tree, i))
    return max_h + 1

n = int(input())
tree = defaultdict(list)
for i in range(n):
    p = int(input())
    tree[p].append(i + 1)
print(tree_height(tree, -1) - 1)