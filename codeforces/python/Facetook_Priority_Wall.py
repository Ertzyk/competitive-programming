my_name = input()
n = int(input())
hashmap, type_to_points = {}, {"posted": 3, "commented": 2, "likes": 1}
for _ in range(n):
    action = input().split()
    X, type, Y = action[0], action[1], action[-2][:-2]
    if X not in hashmap and X != my_name:
        hashmap[X] = 0
    if Y not in hashmap and Y != my_name:
        hashmap[Y] = 0
    if X == my_name:
        hashmap[Y] += type_to_points[type]
    elif Y == my_name:
        hashmap[X] += type_to_points[type]
lst = [[] for _ in range(max(hashmap.values())+1)]
for k, v in hashmap.items():
    lst[v].append(k)
for i in range(len(lst) - 1, -1, -1):
    if len(lst[i]) == 1:
        print(lst[i][0])
    elif len(lst[i]) > 1:
        x = sorted(lst[i])
        for j in x:
            print(j)