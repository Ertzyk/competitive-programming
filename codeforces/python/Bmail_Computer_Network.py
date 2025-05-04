n = int(input())
p = list(map(int, input().split()))
i, path = n - 2, [n]
while i >= 0:
    path.append(p[i])
    i = p[i] - 2
print(" ".join(map(str, path[::-1])))