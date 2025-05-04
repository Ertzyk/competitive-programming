import math
n = int(input())
a = list(map(int, input().split()))
print(max(max(a), math.ceil(sum(a)/(n - 1))))