for _ in range(int(input())):
    x, y = map(int, input().split())
    print(x + y if x > y else x if x == y else y//x*x+(y - y//x*x)//2)