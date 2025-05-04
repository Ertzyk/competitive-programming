from collections import defaultdict, deque
n, m = map(int, input().split())
graph, visited, teams, two_mem_teams, one_mem_teams = defaultdict(list), set(()), [], [], []
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in range(1, n + 1):
    if i not in visited:
        queue, team = deque([i]), set(())
        while queue:
            member = queue.popleft()
            team.add(member)
            for neighbor in graph[member]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        if len(team) > 3:
            print(-1)
            break
        elif len(team) == 3:
            teams.append(team)
        elif len(team) == 2:
            two_mem_teams.append(team)
        else:
            one_mem_teams.append(team)
else:
    for team in two_mem_teams:
        if one_mem_teams:
            p = next(iter(one_mem_teams))
            one_mem_teams.remove(p)
            teams.append(team|p)
        else:
            print(-1)
            break
    else:
        while one_mem_teams:
            it = iter(one_mem_teams)
            a, b, c = next(it), next(it), next(it)
            teams.append(a|b|c)
            one_mem_teams.remove(a)
            one_mem_teams.remove(b)
            one_mem_teams.remove(c)
        for i in teams:
            print(*i)