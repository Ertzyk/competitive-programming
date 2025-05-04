n = int(input())
x = list(map(int, input().split()))
cur_max, res = 0, 0
for i in range(n):
    if x[i] > cur_max:
        cur_max = x[i]
    elif x[i] < cur_max:
        res += cur_max - x[i]
print(res)