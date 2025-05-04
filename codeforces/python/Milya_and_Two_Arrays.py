for _ in range(int(input())):
    n = int(input())
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    print("YES" if len(a) + len(b) >= 4 else "NO")