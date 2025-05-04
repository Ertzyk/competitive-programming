for _ in range(int(input())):
    n = int(input())
    connected_vertices, not_connected_vertices, edges = {1}, {i for i in range(2, n + 1)}, ["!"]
    while len(connected_vertices) < n:
        l, r = 1, next(iter(not_connected_vertices))
        while True:
            print(*["?", l, r], flush=True)
            response = int(input())
            if response == l or response == r:
                edges.append(l)
                edges.append(r)
                connected_vertices.add(r)
                not_connected_vertices.remove(r)
                break
            elif response in connected_vertices:
                l = response
            else:
                r = response
    print(*edges, flush = True)