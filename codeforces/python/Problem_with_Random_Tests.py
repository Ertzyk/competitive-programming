def bitwise_or(list1, list2):
    res, x = [], len(list1)-len(list2)
    if x > 0:
        res = list1[:x]
    for i in range(len(list2)):
        res.append(str(int(list1[i+x])|int(list2[i])))
    return res

n = int(input())
s = input().lstrip("0")
if s:
    k, s = s.find("0"), list(s)
    result, substring = s.copy(), s.copy()
    for i in range(k):
        substring.pop()
        x = bitwise_or(s, substring)
        if x > result:
            result = x
    print("".join(result))
else:
    print(0)