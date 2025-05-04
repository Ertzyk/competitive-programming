def xor(s1, s2):
    res = s1[:-len(s2)]
    for i in range(len(s2)):
        res += str(int(s1[len(s1) - len(s2) + i]) ^ int(s2[i]))
    return res

for _ in range(int(input())):
    s = input()
    count_leading_1, count_next_0, p = 1, 0, 1
    while p < len(s):
        if s[p] == "1":
            count_leading_1 += 1
            p += 1
        else:
            break
    while p < len(s):
        if s[p] == "0":
            count_next_0 += 1
            p += 1
        else:
            break
    if count_next_0 == 0:
        print(1, len(s), 1, 1)
    elif count_next_0 >= count_leading_1:
        print(1, len(s), 1, len(s) - count_leading_1)
    else:
        print(1, len(s), count_leading_1 - count_next_0 + 1, len(s) - count_next_0)