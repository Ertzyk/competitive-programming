for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    left_nums = {i + 1 for i in range(n)}
    for i in range(n):
        while a[i] > 0:
            if a[i] in left_nums:
                left_nums.remove(a[i])
                break
            a[i] //= 2
        else:
            print("NO")
            break
    else:
        print("YES")