a = list(map(int, input().split()))
d, sum_time, min_time, max_time = a[0], a[1], [], []
for i in range(d):
    a = list(map(int, input().split()))
    min_time.append(a[0])
    max_time.append(a[1])
if sum(min_time) <= sum_time <= sum(max_time):
    for i in range(d):
        b = sum_time - sum(min_time)
        if max_time[i] - min_time[i] < b:
            min_time[i] = max_time[i]
        else:
            min_time[i] += b
            break
    print("YES")
    print(" ".join(map(str, min_time)))
else:
    print("NO")