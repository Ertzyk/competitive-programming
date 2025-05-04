for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    startR, startG, startB, m = [], [], [], 0
    for i in s:
        t = m%3 if i == "R" else (m - 1)%3 if i == "G" else (m - 2)%3
        if t == 0:
            startR.append(1)
            startG.append(0)
            startB.append(0)
        elif t == 1:
            startR.append(0)
            startG.append(1)
            startB.append(0)
        else:
            startR.append(0)
            startG.append(0)
            startB.append(1)
        m += 1
    print(startR, startG, startB)