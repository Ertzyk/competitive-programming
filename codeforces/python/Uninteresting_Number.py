for _ in range(int(input())):
    n = input()
    s, twos_threes = 0, {2: 0, 3: 0}
    for i in n:
        s += int(i)
        s %= 9
        if i == "2" and twos_threes[2] < 8:
            twos_threes[2] += 1
        elif i == "3" and twos_threes[3] < 2:
            twos_threes[3] += 1
    combs = {s}
    for i in range(1, twos_threes[3] + 1):
        combs.add((s + i*6)%9)
    cop = combs.copy()
    for j in range(1, twos_threes[2] + 1):
        for i in cop:
            combs.add((i + 2*j)%9)
    print("YES" if 0 in combs else "NO")