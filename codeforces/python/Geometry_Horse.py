n = int(input())
figures, total_figures, f, result, figures_destroyed, i = [], 0, 1, 0, 0, 0
for _ in range(n):
    k, c = map(int, input().split())
    figures.append([c, k])
    total_figures += k
t = int(input())
p = list(map(int, input().split()))
figures.sort()
p.append(float('inf'))
while figures_destroyed < total_figures:
    if figures[i][1] <= p[f - 1] - figures_destroyed:
        result += figures[i][0]*figures[i][1]*f
        figures_destroyed += figures[i][1]
        i += 1
    else:
        result += figures[i][0]*(p[f - 1] - figures_destroyed)*f
        figures[i][1] -= p[f - 1] - figures_destroyed
        figures_destroyed = p[f - 1]
        f += 1
print(result)