for _ in range(int(input())):
    n, m = map(int, input().split())
    matrix1, matrix2, row_permutation, column_permutation = [], [], [], []
    for _ in range(n):
        matrix1.append(list(map(int, input().split())))
    for _ in range(n):
        matrix2.append(list(map(int, input().split())))
    print(matrix1, matrix2)
    for i in matrix2:
        if matrix1[0][0] in i:
            for j in range(m):
                row_permutation.append(i.index(matrix1[0][j]))
    print(row_permutation)