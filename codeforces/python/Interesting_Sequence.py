for _ in range(int(input())):
    n, x = map(int, input().split())
    p = n
    while n > x:
        b = list(bin(n)[2:])
        a = len(b) - 1
        while a >= 0:
            if b[a] == "1":
                while True:
                    b[a] = "0"
                    a -= 1
                    if a < 0 or b[a] == "0":
                        break
                if a == -1:
                    b = ["1"] + b
                else:
                    b[a] = "1"
                break
            a -= 1
        p = int("".join(b), 2)
        n &= p
    print(p if n == x else -1)