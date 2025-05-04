h, w = map(int, input().split())
n = int(input())
d = list(map(int, input().split()))
result = 0
def replaced(h, w, size, i):

    if i == len(d) - 1:
        return (h//size)*(size**2-1) + (w//size)*(size**2-1)
    return (h//size)*(size**2-1) + (w//size)*(size**2-1) + replaced(h//size, w//size, d[i+1]//d[i], i+1)

if h%d[0] or w%d[0]:
    print(-1)
else:
    result = h*w
    result -= replaced(h//d[0], w//d[0], d[1]//d[0], 1)
    print(result)