t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    cur, lengths = 0, []
    for i in range(n):
        s = input()
        lengths.append(len(s))
    for i in range(n):
        cur += lengths[i]
        if cur > m:
            print(i)
            break
    else:
        print(n)