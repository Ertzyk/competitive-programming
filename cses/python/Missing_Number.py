n = int(input())
a = set(map(int, input().split()))
print(next(iter({i for i in range(1, n + 1)} - a)))