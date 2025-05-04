def solve(height, width, r, c):
    if width == 2:
        return True
    if height >= c > width - height:
        return False
    if c <= width - height:
        return solve(width - height, height, c, r)
    return solve(width - height, height, c - height, r)
fibonacci = [1, 1]
for _ in range(44):
    fibonacci.append(fibonacci[-1] + fibonacci[-2])
for _ in range(int(input())):
    n, x, y = map(int, input().split())
    h, w = fibonacci[n], fibonacci[n + 1]
    print("YES" if solve(h, w, x, y) else "NO")