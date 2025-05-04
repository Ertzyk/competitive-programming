t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    max_num = 0
    for i in p:
        if i > max_num:
            max_num = i
        elif i < max_num - 1:
            print("NO")
            break
    else:
        print("YES")