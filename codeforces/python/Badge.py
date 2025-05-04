n = int(input())
p = list(map(int, input().split()))
result = [None]*n
for i in range(n):
    if result[i] is None:
        tortoise, hare = p[i], p[p[i] - 1]
        while tortoise != hare:
            tortoise, hare = p[tortoise - 1], p[p[hare - 1] - 1]
        tortoise = i + 1
        while tortoise != hare:
            tortoise, hare = p[tortoise - 1], p[hare - 1]
        start_cycle, tortoise = tortoise, i + 1
        while tortoise != start_cycle:
            result[tortoise - 1], tortoise = start_cycle, p[tortoise - 1]
        result[start_cycle - 1], tortoise = start_cycle, p[start_cycle - 1]
        while tortoise != start_cycle:
            result[tortoise - 1], tortoise = tortoise, p[tortoise - 1]
print(*result)