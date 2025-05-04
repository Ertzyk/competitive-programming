n = int(input())
p = list(map(int, input().split()))
visited, sizes = set(()), []
for i in range(n):
    if i not in visited:
        visited.add(i)
        pointer, size = p[i] - 1, 1
        while pointer != i:
            visited.add(pointer)
            size += 1
            pointer = p[pointer] - 1
        sizes.append(size)
if len(sizes) == 1:
    print(sizes[0]**2)
else:
    if sizes[0] > sizes[1]:
        first_max, second_max = sizes[0], sizes[1]
    else:
        first_max, second_max = sizes[1], sizes[0]
    for i in range(2, len(sizes)):
        if sizes[i] > first_max:
            second_max, first_max = first_max, sizes[i]
        elif sizes[i] > second_max:
            second_max = sizes[i]
    print(sum(map(lambda x: x**2, sizes)) + 2*first_max*second_max)