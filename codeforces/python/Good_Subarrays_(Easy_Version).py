for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    prev, result = 0, 0
    for i in range(n):
        prev = min(a[i], prev + 1)
        result += prev
    print(result)