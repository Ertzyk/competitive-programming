from collections import Counter
for _ in range(int(input())):
    y = list(map(int, list(input())))
    c = Counter(y)
    print("red" if len(c.keys()) == 1 and list(c.keys())[0] == 0 or (c.get(0, 0) > 1 or c.get(0, 0) > 0 and (c.get(2, 0) > 0 or c.get(4, 0) > 0 or c.get(6, 0) > 0 or c.get(8, 0) > 0)) and sum(y)%3 == 0 else "cyan")