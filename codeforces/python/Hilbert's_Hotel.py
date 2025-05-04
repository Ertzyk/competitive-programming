for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    visited = set(())
    for i in range(n):
        if (a[i] + i)%n in visited:
            print("NO")
            break
        visited.add((a[i] + i)%n)
    else:
        print("YES")