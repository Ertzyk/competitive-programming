t = int(input())
for _ in range(t):
    n = int(input())
    r1, c1, r2, c2, r3, c3 = map(int, input().split())
    cricket = {(r1, c1), (r2, c2), (r3, c3)}
    x, y = map(int, input().split())
    if cricket == {(1, 1), (2, 1), (1, 2)}:
        print("YES" if x == 1 or y == 1 else "NO")
    elif cricket == {(1, n), (1, n-1), (2, n)}:
        print("YES" if x == 1 or y == n else "NO")
    elif cricket == {(n, n), (n-1, n), (n, n-1)}:
        print("YES" if x == n or y == n else "NO")
    elif cricket == {(n, 1), (n-1, 1), (n, 2)}:
        print("YES" if x == n or y == 1 else "NO")
    else:
        r1, c1, r2, c2, r3, c3 = map(lambda x: int(x) % 2, [r1, c1, r2, c2, r3, c3])
        x, y = map(lambda x: int(x) % 2, [x, y])
        for r, c in [(r1, c1), (r2, c2), (r3, c3)]:
            if r == x and c == y:
                print("YES")
                break
        else:
            print("NO")