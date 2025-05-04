n = int(input())
a = list(map(int, input().split()))
runs, run = [], [a[0]]
for p in range(1, n):
    if a[p - 1] < a[p]:
        run.append(a[p])
    else:
        runs.append(run)
        run = [a[p]]
runs.append(run)
if len(runs) == 1:
    print(n)
else:
    result = max(map(len, runs)) + 1
    for i in range(len(runs) - 1):
        x = runs[i] + runs[i + 1]
        if len(x) <= result:
            continue
        x[len(runs[i]) - 1] = x[len(runs[i])] - 1
        for j in range(len(x) - 1):
            if x[j] >= x[j + 1]:
                break
        else:
            result = max(result, len(x))
        x[len(runs[i]) - 1] = runs[i][-1]
        x[len(runs[i])] = x[len(runs[i]) - 1] + 1
        for j in range(len(x) - 1):
            if x[j] >= x[j + 1]:
                break
        else:
            result = max(result, len(x))
    print(result)