from collections import defaultdict, deque
n, x = map(int, input().split())
a = list(map(int, input().split()))
graph, visited, sizes, pointer, place, possible_sums = defaultdict(list), set(()), [], x, 0, {0}
while pointer != 0:
    pointer = a[pointer - 1]
    place += 1
for i in range(n):
    if a[i] != 0:
        graph[a[i]].append(i + 1)
        graph[i + 1].append(a[i])
for i in range(1, n + 1):
    if i not in visited:
        visited.add(i)
        queue, count, flag = deque([i]), 0, True
        while queue:
            num = queue.popleft()
            if num == x:
                flag = False
            if flag:
                count += 1
            for j in graph[num]:
                if j not in visited:
                    visited.add(j)
                    queue.append(j)
        if flag:
            sizes.append(count)
for i in sizes:
    new_sums = {i + j for j in possible_sums}
    possible_sums.update(new_sums)
for i in sorted(list(possible_sums)):
    print(i + place)