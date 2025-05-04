n = int(input())
a = list(map(int, input().split()))
freq = [0]*(max(a)+1)
for i in a:
    freq[i] += 1
a = 0
b = freq[1]
for i in range(2, len(freq)):
     a, b = b, max(b, a+freq[i]*i)
print(b)