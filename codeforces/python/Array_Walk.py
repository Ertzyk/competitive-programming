def solve(arr, z):
    if z == 0 or len(arr) == 2:
        return sum(arr) - arr[0] - arr[1]
    if len(arr) == 3:
        return max(arr[0], arr[2])
    return max(arr[0] + arr[1] + solve(arr[:-2], z - 1), arr[2] + solve(arr[1:], z))

for _ in range(int(input())):
    _, k, z = map(int, input().split())
    a = list(map(int, input().split()))[:k + 1]
    n = k + 1
    print(a[0] + a[1] + solve(a, z))