from collections import defaultdict
n, tree = int(input()), defaultdict(list)
for i in range(n - 1):
    tree[int(input())].append(i + 2)
for i in tree.keys():
    count_leaves = 0
    for j in tree[i]:
        if j not in tree:
            count_leaves += 1
    if count_leaves < 3:
        print("No")
        break
else:
    print("Yes")