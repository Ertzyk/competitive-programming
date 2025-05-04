for _ in range(int(input())):
    n = int(input())
    s = input()
    if ">" in s and "<" in s:
        result, i = 0, 0
        while i < n:
            if s[i] == "-":
                while True:
                    result += 1
                    i += 1
                    if i == n or s[i] != "-":
                        break
                result += 1
            i += 1
        if s[0] == "-" and s[-1] == "-":
            result -= 1
        print(result)
    else:
        print(n)