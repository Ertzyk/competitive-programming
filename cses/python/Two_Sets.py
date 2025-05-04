n = int(input())
if n%4 == 1 or n%4 == 2:
    print("NO")
else:
    print("YES")
    A, B = [], []
    if n%4:
        for i in range(1, n + 1):
            if i%4 == 1 or i%4 == 2:
                A.append(i)
            else:
                B.append(i)
    else:
        for i in range(1, n + 1):
            if i%4 == 0 or i%4 == 1:
                A.append(i)
            else:
                B.append(i)
    print(len(A))
    print(*A)
    print(len(B))
    print(*B)