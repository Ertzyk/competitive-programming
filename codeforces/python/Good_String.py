from collections import Counter
t = int(input())
for _ in range(t):
    s = input()
    x = Counter(s)
    result = max(x.values())
    for i in x:
        if x[i]*2 <= result:
            continue
        for j in x:
            if x[j]*2 <= result or i == j:
                continue
            cur, swaps = "", 0
            for letter in s:
                if (letter == i or letter == j) and cur != letter:
                    cur = letter
                    swaps += 1
            swaps -= 1 if swaps%2 else 0
            result = max(result, swaps)
    print(len(s) - result)


