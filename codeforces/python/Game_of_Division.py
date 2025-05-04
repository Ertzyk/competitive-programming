from collections import Counter
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(lambda x: x%k, a))
    c = Counter(b)
    for i in c:
        if c[i] == 1:
            print("YES")
            for j in range(len(a)):
                if a[j]%k == i:
                    print(j + 1)
                    break
            break
    else:
        print("NO")