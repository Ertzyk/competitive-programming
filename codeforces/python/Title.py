k = int(input())
s = list(input())
undecided, must_use_letters = [], {chr(ord("a") + i) for i in range(k)}
for i in range((len(s) + 1)//2):
    if s[i] != "?" and s[- i - 1] != "?":
        if s[i] != s[- i - 1]:
            print("IMPOSSIBLE")
            break
        elif s[i] in must_use_letters:
            must_use_letters.remove(s[i])
    elif s[i] == "?" and s[- i - 1] != "?":
        s[i] = s[- i - 1]
        if s[- i - 1] in must_use_letters:
            must_use_letters.remove(s[- i - 1])
    elif s[i] != "?" and s[- i - 1] == "?":
        s[- i - 1] = s[i]
        if s[i] in must_use_letters:
            must_use_letters.remove(s[i])
    elif s[i] == "?" and s[- i - 1] == "?":
        undecided.append(i)
else:
    if len(must_use_letters) > len(undecided):
        print("IMPOSSIBLE")
    else:
        for p in range(len(undecided)):
            if p < len(undecided) - len(must_use_letters):
                x = "a"
            else:
                x = min(must_use_letters)
                must_use_letters.remove(x)
            s[undecided[p]] = x
            s[- undecided[p] - 1] = x
        print("".join(s))