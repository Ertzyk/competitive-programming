t = int(input())
for j in range(t):
    n = int(input())
    print(-1 if n%2 and n<=25 else " ".join(["1"] + [str(i//2) for i in range(4, 12)] + ["1"] + [str(i//2) for i in range(12, 24)] + ["13", "12", "12", "1", "13"] + [str(i//2) for i in range(28, n+1)]) if n%2 else " ".join([str(i//2+1) for i in range(n)]))