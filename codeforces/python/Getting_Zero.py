from collections import deque
n = int(input())
a = list(map(int, input().split()))
result, pre_calc, queue, visited = [], [0]*32768, deque([(0, 0)]), {0}
while queue:
    num, depth = queue.popleft()
    pre_calc[num] = depth
    if (num - 1)%32768 not in visited:
        visited.add((num - 1)%32768)
        queue.append(((num - 1)%32768, depth + 1))
    if num%2 == 0 and num//2 not in visited:
        visited.add(num//2)
        queue.append((num//2, depth + 1))
    if num%2 == 0 and (num + 32768)//2 not in visited:
        visited.add((num + 32768)//2)
        queue.append(((num + 32768)//2, depth + 1))
for i in a:
    result.append(pre_calc[i])
print(*result)