from collections import Counter
for _ in range(int(input())):
    n = int(input())
    s = list(input())
    c = Counter(s)
    if c["0"]%2 or s[0] == "0" or s[-1] == "0":
        print("NO")
    else:
        count_1 = 0
        for i in range(len(s)):
            if s[i] == "1" and count_1 < c["1"]//2:
                s[i] = "0"
                count_1 += 1
            elif s[i] == "0":
                s[i] = "A" if c["0"]%2 else "B"
                c["0"] -= 1
        print("YES")
        print("".join(s).translate(str.maketrans("10AB", ")(()")))
        print("".join(s).translate(str.maketrans("10AB", ")()(")))