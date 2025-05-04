from collections import defaultdict, deque
for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    graph, visited, result = defaultdict(list), set(()), 0
    for i in range(n):
        if i + k < n:
            graph[i].append(i + k)
        if i - k >= 0:
            graph[i].append(i - k)
        graph[i].append(n - 1 - i)
    for i in range(n):
        if i not in visited:
            visited.add(i)
            queue, count_letters = deque([i]), [0]*26
            while queue:
                vertex = queue.popleft()
                count_letters[ord(s[vertex]) - ord("a")] += 1
                for j in graph[vertex]:
                    if j not in visited:
                        queue.append(j)
                        visited.add(j)
            result += max(count_letters)
    print(len(s) - result)