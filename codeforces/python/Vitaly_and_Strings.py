s = list(input())
t = input()
for i in range(len(s) - 1, -1, -1):
    if s[i] == "z":
        s[i] = "a"
    else:
        s[i] = chr(ord(s[i]) + 1)
        break
res = "".join(s)
print("No such string" if res == t else res)