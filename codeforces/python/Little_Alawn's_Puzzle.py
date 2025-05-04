for _ in range(int(input())):
    n = int(input())
    p1 = list(map(int, input().split()))
    p2 = list(map(int, input().split()))
    graph, count_cycles, visited = [0]*(n + 1), 0, set(())
    for i in range(n):
        graph[p1[i]] = p2[i]
    for i in range(1, n + 1):
        if i not in visited:
            visited.add(i)
            p = i
            while True:
                p = graph[p]
                visited.add(p)
                if p == i:
                    break
            count_cycles += 1
    print(pow(2, count_cycles, 10**9 + 7))