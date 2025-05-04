n, k = map(int, input().split())
a = list(map(int, input().split()))
consecutive_zeros, consecutive_ones, prev, count, res_len, res_lst, l, r, zeros_diff = [], [], a[0], 1, 0, a[::], 0, 0, 0
for i in range(1, n):
    if a[i] != prev:
        if prev == 0:
            consecutive_zeros.append(count)
        else:
            consecutive_ones.append(count)
        prev, count = a[i], 1
    else:
        count += 1
if prev == 0:
    consecutive_zeros.append(count)
else:
    consecutive_ones.append(count)
print(consecutive_zeros, consecutive_ones)
count_ones = 0
while r < len(consecutive_zeros):
    if zeros_diff + consecutive_zeros[r] <= k:
        zeros_diff += consecutive_zeros[r]
        r += 1
