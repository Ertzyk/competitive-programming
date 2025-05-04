import math
t = int(input())

for i in range(t):
    n = int(input())
    a = input().split()
    k = 0
    for j in range(math.floor(len(a)-1/2)-1, -1, -1):
        k += min(int(a[j]==a[len(a)-j-2]) + int(a[j+1]==a[len(a)-j-1]), int(a[j]==a[j+1]) + int(a[len(a)-j-2]==a[len(a)-j-1]))
    print(k//2)