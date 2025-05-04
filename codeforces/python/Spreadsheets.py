for _ in range(int(input())):
    c = input()
    a = list(map(lambda x: 0 if x.isdigit() else 1, c))
    if a.count(1) == 2 and a[1] == 0:
        x = c[1:].split("C")
        b, res = int(x[1]), ""
        while b != 0:
            res += "Z" if b%26 == 0 else chr(b%26 - 1 + ord("A"))
            b = (b - 1)//26
        print(res[::-1] + x[0])
    else:
        letters, res = c[:a.count(1)], 0
        for i in range(len(letters) - 1, -1, -1):
            res += (ord(letters[i]) - ord("A") + 1)*26**(len(letters) - 1 - i)
        print("R" + c[a.count(1):] + "C" + str(res))