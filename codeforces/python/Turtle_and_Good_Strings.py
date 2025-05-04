t = int(input())

for i in range(t):
    n = int(input())
    s = input()
    print("NO" if s[0] == s[n-1] else "YES")