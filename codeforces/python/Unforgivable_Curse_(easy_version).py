from collections import Counter
for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    t = input()
    if n < 4:
        print("YES" if s == t else "NO")
    elif n == 4:
        print("YES" if s == t or s[1] == t[1] and s[2] == t[2] and s[0] == t[3] and s[3] == t[0] else "NO")
    elif n == 5:
        count_s, count_t = Counter(s), Counter(t)
        count_s[s[2]] -= 1
        count_t[t[2]] -= 1
        print("YES" if count_s == count_t and s[2] == t[2] else "NO")
    else:
        print("YES" if Counter(s) == Counter(t) else "NO")