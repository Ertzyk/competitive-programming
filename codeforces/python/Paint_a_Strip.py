for _ in range(int(input())):
    n = int(input())
    if n == 1:
        print(1)
    else:
        s = 2
        while n > 4:
            s += 1
            n = (n+1)//2-1
        print(s)