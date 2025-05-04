def is_palindrome(word):
    for i in range(len(word)//2):
        if word[i] != word[-i-1]:
            return i
    return -1
t = int(input())
for _ in range(t):
    s = input()
    print(len(s))
    c = is_palindrome(s)
    if c == -1:
        print(s)
    else:
        for diff in range(len(s)-1):
            for l in range(len(s)-diff):
                r = l + diff
                if l > c and r < len(s) - 1 - c:
                    continue
                x = s[:l] + s[r+1:]
                if is_palindrome(x) == -1:
                    print(x)
                    break
            else:
                continue
            break
        else:
            continue