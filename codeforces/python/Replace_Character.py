from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    string = input()
    s, min_value, max_value, min_key, max_key, x = Counter(string), float('inf'), 0, "", "", list(string)
    for i in s:
        if s[i] < min_value:
            min_value = s[i]
            min_key = i
        if s[i] >= max_value:
            max_value = s[i]
            max_key = i
    for i in range(n):
        if x[i] == min_key:
            x[i] = max_key
            break
    print("".join(x))