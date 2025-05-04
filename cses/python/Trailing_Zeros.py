n = int(input())//5
res = 0
while n:
    res += n
    n //= 5
print(res)