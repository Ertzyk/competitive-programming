for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    strong_vertices, max_value = [], -2*10**9
    for i in range(n):
        c = a[i] - b[i]
        if c > max_value:
            max_value, strong_vertices = c, [i + 1]
        elif c == max_value:
            strong_vertices.append(i + 1)
    print(len(strong_vertices))
    print(*strong_vertices)