for _ in range(int(input())):
    n, m, k = map(int, input().split())
    print("YES" if (k > 3 and m >= n - 1 or k == 3 and (n - 1)*n//2 == m or k == 2 and n == 1 and m == 0) and (n - 1)*n//2 >= m else "NO")