n, k, s = map(int, input().split())
if s > (n - 1)*k or s < k:
    print("NO")
else:
    print("YES")
    position, direction, res = 1, 1, []
    for _ in range(s%k):
        position += (s//k + 1)*direction
        direction *= -1
        res.append(position)
    for _ in range(k - s%k):
        position += s//k*direction
        direction *= -1
        res.append(position)
    print(*res)