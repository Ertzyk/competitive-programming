n = int(input())
f = list(map(int, input().split()))
for i in range(n):
    if f[f[f[i]-1]-1]-1 == i:
        print("YES")
        break
else:
    print("NO")