k, r = map(int, input().split())
c, i = k, 1
while True:
    if c%10 == r or c%10 == 0:
        print(i)
        break
    c += k
    i += 1