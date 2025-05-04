for _ in range(int(input())):
    n = int(input())
    row1 = list(input())
    row2 = input()
    result = 0
    for i in range(n):
        if row2[i] == "1":
            if row1[i] == "0" or i > 0 and row1[i - 1] == "1":
                result += 1
            elif i < n - 1 and row1[i + 1] == "1":
                result += 1
                row1[i + 1] = "0"
    print(result)