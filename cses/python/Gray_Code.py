def solve(n):
    if n == 1:
        return ["0", "1"]
    x = solve(n - 1)
    return list(map(lambda b: "0" + b, x)) + list(map(lambda b: "1" + b, x[::-1]))
n = int(input())
for i in solve(n):
    print(i)