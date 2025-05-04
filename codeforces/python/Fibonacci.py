def matrix_multiplication(A, B):
    C = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                C[i][j] += A[i][k] * B[k][j]
    return C

def mod_exp(matrix, power):
    if power == 1:
        return matrix
    if power%2 == 0:
        new_matrix = matrix_multiplication(matrix, matrix)
        new_matrix[0][0] %= 10**9+7
        new_matrix[0][1] %= 10**9+7
        new_matrix[1][0] %= 10**9+7
        new_matrix[1][1] %= 10**9+7
        return mod_exp(new_matrix, power//2)
    b = matrix_multiplication(matrix, mod_exp(matrix, power - 1))
    b[0][0] %= 10 ** 9 + 7
    b[0][1] %= 10 ** 9 + 7
    b[1][0] %= 10 ** 9 + 7
    b[1][1] %= 10 ** 9 + 7
    return b

n = int(input())
print(0 if n == 0 else 1 if n == 1 else mod_exp([[1, 1], [1, 0]], n - 1)[0][0])