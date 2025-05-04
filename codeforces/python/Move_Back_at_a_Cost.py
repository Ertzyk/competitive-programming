t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    stop, min_moved = len(a) - 1, float('inf')
    while stop > 0 and a[stop] >= a[stop - 1]:
        stop -= 1

    if stop == 0:
        print(" ".join(map(str, a)))
    else:
        for i in range(stop):
            if a[i] > min(a[i+1:stop+1]):
                a[i] += 1
                min_moved = min(min_moved, a[i])

        for i in range(stop + 1, len(a)):
            if a[i] > min_moved:
                a[i] += 1
        print(" ".join(map(str, sorted(a))))
