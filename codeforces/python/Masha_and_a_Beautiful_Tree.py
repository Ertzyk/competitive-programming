def permute_subtree(lst):
    if max(lst) - min(lst) != len(lst) - 1:
        return float("-inf")
    if len(lst) == 2:
        return 0 if lst[1] > lst[0] else 1
    b = permute_subtree(lst[:len(lst)//2])
    if b == float("-inf"):
        return float("-inf")
    b += permute_subtree(lst[len(lst)//2:])
    if b == float("-inf"):
        return float("-inf")
    return b + (0 if lst[0] < lst[-1] else 1)
for _ in range(int(input())):
    m = int(input())
    p = list(map(int, input().split()))
    if m == 1:
        print(0)
    elif m == 2:
        print(0 if p[0] < p[1] else 1)
    else:
        a = permute_subtree(p[:m//2]) + permute_subtree(p[m//2:]) + (0 if p[0] < p[-1] else 1)
        print(a if a != float('-inf') else -1)