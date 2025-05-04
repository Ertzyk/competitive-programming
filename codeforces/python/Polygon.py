for _ in range(int(input())):
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append(input())
    for i in range(n - 1):
        for j in range(n - 1):
            if matrix[i][j] == "1" and matrix[i + 1][j] == "0" and matrix[i][j + 1] == "0":
                print("NO")
                break
        else:
            continue
        break
    else:
        print("YES")