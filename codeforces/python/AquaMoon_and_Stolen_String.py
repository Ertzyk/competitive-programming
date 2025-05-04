for _ in range(int(input())):
    n, m = map(int, input().split())
    res = [[0 for _ in range(26)] for _ in range(m)]
    for _ in range(n):
        word = input()
        for i in range(m):
            res[i][ord(word[i])-ord("a")] += 1
    for _ in range(n - 1):
        word = input()
        for i in range(m):
            res[i][ord(word[i])-ord("a")] -= 1
    result = ""
    for i in res:
        result += chr(i.index(1) + ord('a'))
    print(result)