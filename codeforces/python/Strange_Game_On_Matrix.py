n, m, k = map(int, input().split())
matrix, score, total_removed = [], 0, 0
for _ in range(n):
    matrix.append(list(map(int, input().split())))
for i in range(m):
    cur_max, removed_ones, cur_score, l, r, min_removed_ones = 0, 0, matrix[0][i], 0, 0, 0
    while r < n - 1:
        while l < n and matrix[l][i] == 0:
            l += 1
        while r < n - 1 and r - l < k - 1:
            r += 1
            cur_score += matrix[r][i]
        if cur_score > cur_max:
            cur_max, removed_ones = cur_score, min_removed_ones
        cur_score -= 1
        min_removed_ones += 1
        l += 1
    total_removed += removed_ones
    score += max(cur_max, cur_score)
print(score, total_removed)