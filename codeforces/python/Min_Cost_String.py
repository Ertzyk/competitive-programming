n, k = map(int, input().split())
core = ""
for i in range(k):
    core += chr(ord('a') + i)
    for j in range(i + 1, k):
        core += chr(ord('a') + i) + chr(ord('a') + j)
print((core*((n - 1)//len(core) + 1))[:n])