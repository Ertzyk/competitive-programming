t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1 or n == 3:
        print(-1)
    elif n%2:
        res = ""
        for _ in range((n-5)//2):
            res += "33"
        res += "36366"
        print(res)
    else:
        res = ""
        for _ in range((n-2)//2):
            res += "33"
        res += "66"
        print(res)