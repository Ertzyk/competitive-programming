t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    if a == 1:
        print("No" if (n-1)%b else "Yes")
    else:
        k = 1
        while k <= n:
            if k%b == n%b:
                print("Yes")
                break
            k *= a
        else:
            print("No")