for _ in range(int(input())):
    l, r = map(int, input().split())
    a = list(map(int, input().split()))
    count_digits, res = [0]*17, ""
    for i in range(r + 1):
        b = bin(a[i])[2:].zfill(17)
        for j in range(17):
            if b[j] == "1":
                count_digits[j] += 1
    for i in range(17):
        res += "1" if count_digits[i]*2 > r + 1 else "0"
    print(int(res, 2))