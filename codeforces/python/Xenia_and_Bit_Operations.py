n, m = map(int, input().split())
a = list(map(int, input().split()))
tree, operation = [0] * (2**(n + 1)), 1
for i in range(2**n):
    tree[2**n + i] = a[i]
for i in range(2**n - 1, 0, -1):
    tree[i] = tree[i*2] | tree[i*2 + 1] if operation == 1 else tree[i*2] ^ tree[i*2 + 1]
    if i & (i - 1) == 0:
        operation = -operation
for _ in range(m):
    p, b = map(int, input().split())
    tree[2**n + p - 1], pointer, operation = b, (2**n + p - 1)//2, 1
    while pointer != 0:
        tree[pointer] = tree[pointer*2] | tree[pointer*2 + 1] if operation == 1 else tree[pointer*2] ^ tree[pointer*2 + 1]
        pointer //= 2
        operation = -operation
    print(tree[1])