for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    s = input()
    result = [-1]*n
    for i in range(n):
        if result[i] == -1:
            start, pointer, count_black = i + 1, i + 1, 0
            while True:
                if s[pointer - 1] == "0":
                    count_black += 1
                pointer = p[pointer - 1]
                if pointer == start:
                    break
            while True:
                result[pointer - 1] = count_black
                pointer = p[pointer - 1]
                if pointer == start:
                    break
    print(*result)