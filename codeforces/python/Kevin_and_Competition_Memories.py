for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = sorted(list(map(int, input().split())))
    kevin_rating = a[0]
    a = sorted([i for i in a if i > kevin_rating])
    c = [len(a)] * len(b)
    pointer1, pointer2, cur = len(a) - 1, len(b) - 1, 0
    while pointer1 > -1 and pointer2 > -1:
        if b[pointer2] <= kevin_rating:
            break
        while pointer1 > -1 and a[pointer1] >= b[pointer2]:
            cur += 1
            pointer1 -= 1
        c[pointer2] = cur
        pointer2 -= 1
    num_of_prob_kev_can_solve = -1
    for i in range(len(b)):
        if b[i] > kevin_rating:
            num_of_prob_kev_can_solve = i
            break
    if num_of_prob_kev_can_solve == -1:
        num_of_prob_kev_can_solve = len(b)
    result, sum_of_ranks = [], 0
    for k in range(1, m + 1):
        rank = num_of_prob_kev_can_solve//k
        i = len(b) + num_of_prob_kev_can_solve%k - k
        while i >= num_of_prob_kev_can_solve:
            rank += c[i] + 1
            i -= k
        result.append(rank)
    print(*result)