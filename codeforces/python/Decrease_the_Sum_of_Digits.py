t = int(input())

def sum_of_digits(x):
    res = 0
    for i in x:
        res += i
    return res

for _ in range(t):
    original_num, s = list(map(int, input().split()))
    n = [0] + list(map(int, str(original_num)))
    i = len(n) - 1
    while True:
        if sum_of_digits(n) > s:
            n[i] = 0
            i -= 1
            while n[i] == 9:
                n[i] = 0
                i -= 1
            n[i] += 1
        else:
            print(int("".join(map(str, n))) - original_num)
            break