t = int(input())
for _ in range(t):
    n = int(input())
    a = input().split()
    result = 0 if a[0] == "0" else 1
    a = a[1:]
    for i in "".join(a).split("0"):
        result += len(i)//3
    print(result)