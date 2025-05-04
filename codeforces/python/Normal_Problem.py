for _ in range(int(input())):
    s = list(input())
    for i in range(len(s)):
        if s[i] == "p":
            s[i] = "q"
        elif s[i] == "q":
            s[i] = "p"
    print("".join(s)[::-1])