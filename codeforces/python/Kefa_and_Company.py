n, d = map(int, input().split())
friendship, lst_friends = {}, []
for _ in range(n):
    m, s = map(int, input().split())
    friendship[m] = friendship.get(m, 0) + s
for i in friendship:
    lst_friends.append((i, friendship[i]))
lst_friends.sort(key = lambda x : x[0])
result, s, l_index, l_value = 0, 0, 0, lst_friends[0][0]
for r_index in range(len(lst_friends)):
    r_value = lst_friends[r_index][0]
    s += lst_friends[r_index][1]
    while r_value - l_value >= d:
        s -= lst_friends[l_index][1]
        l_index += 1
        l_value = lst_friends[l_index][0]
    result = max(result, s)
print(result)