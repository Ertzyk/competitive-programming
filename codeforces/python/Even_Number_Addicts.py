t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(lambda x: int(x)%2, input().split()))
    z, o = a.count(0), a.count(1)
    print("Bob" if o%4 == 1 and z%2 == 0 or o%4 == 2 else "Alice")