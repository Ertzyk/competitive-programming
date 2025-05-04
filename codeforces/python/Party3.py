from collections import defaultdict, deque
n = int(input())
friend_graph, enemy_graph, visited, result = defaultdict(list), defaultdict(list), set(()), 0
for _ in range(int(input())):
    u, v = map(int, input().split())
    friend_graph[u].append(v)
    friend_graph[v].append(u)
for _ in range(int(input())):
    u, v = map(int, input().split())
    enemy_graph[u].append(v)
    enemy_graph[v].append(u)
for i in range(1, n + 1):
    if i not in visited:
        visited.add(i)
        queue, group = deque([i]), set(())
        while queue:
            person = queue.popleft()
            group.add(person)
            for j in friend_graph[person]:
                if j not in visited:
                    queue.append(j)
                    visited.add(j)
        if len(group) > result:
            if len(group) <= 2:
                result = len(group)
            else:
                for j in group:
                    for k in enemy_graph[j]:
                        if k in group:
                            break
                        enemy_graph[k].remove(j)
                    else:
                        continue
                    break
                else:
                    result = len(group)
print(result)