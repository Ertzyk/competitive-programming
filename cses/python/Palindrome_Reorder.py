from collections import Counter
c, res, odd_letter = Counter(input()), "", ""
for i in c:
    if c[i]%2 == 0:
        res += i*(c[i]//2)
    elif not odd_letter:
        odd_letter = i
    else:
        print("NO SOLUTION")
        break
else:
    print(res + (odd_letter*(c[odd_letter]) + res[::-1] if odd_letter else res[::-1]))