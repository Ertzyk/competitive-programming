from collections import Counter
for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    t = input()
    if n <= k:
        print("YES" if s == t else "NO")
    else:
        count_s, count_t = Counter(s), Counter(t)
        for i in range(n - k, k):
            if s[i] != t[i]:
                print("NO")
                break
            count_s[s[i]] -= 1
            count_t[t[i]] -= 1
        else:
            print("YES" if count_s == count_t else "NO")