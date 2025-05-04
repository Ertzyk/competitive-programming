m, n = map(int, input().split())
result = 0
for i in range(m):
    result += (i+1)*(((i+1)/m)**n - (i/m)**n)
print(result)