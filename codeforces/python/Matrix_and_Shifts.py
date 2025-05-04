for _ in range(int(input())):
    _ = input()
    n = int(input())
    matrix, max_conseq, count_ones = [input() for _ in range(n)], 0, 0
    for i in range(n):
        local_count_ones = 0
        for j in range(n):
            if matrix[j][(i + j)%n] == "1":
                local_count_ones += 1
        count_ones += local_count_ones
        max_conseq = max(max_conseq, local_count_ones)
    print(n - 2*max_conseq + count_ones)