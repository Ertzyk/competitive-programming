from collections import defaultdict

def h_tree(tree, root):
    result = 0
    for i in tree[root]:
        result = max(result, h_tree(tree, i))
    return result + 1

n = int(input())
tree = defaultdict(list)
for _ in range(n):
    line = input().split(" reposted ")
    tree[line[1].lower()].append(line[0].lower())

print(h_tree(tree, "polycarp"))