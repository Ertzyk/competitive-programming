t = int(input())
for _ in range(t):
    n = int(input())
    row1 = list(map(int, input().split()))
    row2 = list(map(int, input().split()))
    max_not_chosen, result = -10000, 0
    for i in range(n):
        if row1[i] >= row2[i]:
            result += row1[i]
            max_not_chosen = max(max_not_chosen, row2[i])
        else:
            result += row2[i]
            max_not_chosen = max(max_not_chosen, row1[i])
    print(result + max_not_chosen)