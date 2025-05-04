n = int(input())
name_to_score, score_memory, max_score = {}, [], 0
for i in range(n):
    x = input().split()
    name, score = x[0], int(x[1])
    name_to_score[name] = name_to_score.get(name, 0) + score
    score_memory.append([name, score])
for i in name_to_score:
    if name_to_score[i] > max_score:
        max_names, max_score = {i}, name_to_score[i]
    elif name_to_score[i] == max_score:
        max_names.add(i)
name_to_score = {}
if len(max_names) == 1:
    print(list(max_names)[0])
else:
    for i in score_memory:
        if i[0] in max_names:
            name_to_score[i[0]] = name_to_score.get(i[0], 0) + i[1]
            if name_to_score[i[0]] >= max_score:
                print(i[0])
                break