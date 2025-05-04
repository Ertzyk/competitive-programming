for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    seen = set(())
    for i in a:
        if i not in seen:
            seen.add(i)
        else:
            print("NO")
            break
    else:
        print("YES")