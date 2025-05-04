n, m = map(int, input().split())
s = ["x"] + list(input()) + ["x"]
cur = 0
for i in range(1, n):
    if s[i] == "." and s[i + 1] == ".":
        cur += 1
for _ in range(m):
    x, c = input().split()
    x = int(x)
    if c == "." and s[x] != "." or c != "." and s[x] == ".":
        cur += int(s[x - 1] == ".") + int(s[x + 1] == ".") if c == "." else -(int(s[x - 1] == ".") + int(s[x + 1] == "."))
    s[x] = c
    print(cur)