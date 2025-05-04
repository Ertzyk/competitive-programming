for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    left_max, right_min, l_cur_max, r_cur_min, result = [], [], 0, float("inf"), 1
    for i in range(n - 1):
        if p[i] > l_cur_max:
            l_cur_max = p[i]
        left_max.append(l_cur_max)
        if p[-i - 1] < r_cur_min:
            r_cur_min = p[-i - 1]
        right_min.append(r_cur_min)
    for i in range(n - 1):
        if left_max[i] < right_min[-i - 1]:
            result += 1
    print(result)