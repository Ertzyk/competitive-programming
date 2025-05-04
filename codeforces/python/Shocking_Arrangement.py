for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    positive_integers, negative_integers, result, cur_sum = [], [], [], 0
    for i in range(n):
        if a[i] > 0:
            positive_integers.append(a[i])
        elif a[i] < 0:
            negative_integers.append(a[i])
        else:
            result.append(0)
    if len(result) == n:
        print("No")
    else:
        positive_integers.sort()
        negative_integers.sort()
        print("Yes")
        while len(result) < n:
            if cur_sum > 0:
                x = negative_integers.pop()
            else:
                x = positive_integers.pop()
            cur_sum += x
            result.append(x)
        print(*result)