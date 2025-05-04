from collections import defaultdict
n = int(input())
names = [input() for _ in range(n)]
order, graph, result = [], defaultdict(dict), ""
for i in range(n - 1):
    if len(names[i]) > len(names[i + 1]) and names[i][:len(names[i + 1])] == names[i + 1]:
        print("Impossible")
        break
    elif len(names[i]) < len(names[i + 1]) and names[i + 1][:len(names[i])] == names[i]:
        continue
    else:
         for j in range(len(names[i])):
             if names[i][j] != names[i + 1][j]:
                 if graph[names[i][j]].get("O", None) is None:
                     graph[names[i][j]]["O"] = [names[i + 1][j]]
                 else:
                     graph[names[i][j]]["O"].append(names[i + 1][j])
                 if graph[names[i + 1][j]].get("I", None) is None:
                     graph[names[i + 1][j]]["I"] = [names[i][j]]
                 else:
                     graph[names[i + 1][j]]["I"].append(names[i][j])
                 break
else:
    while graph:
        for key in graph:
            if len(graph[key].get("I", [])) == 0:
                result += key
                for neighbor in graph[key].get("O", []):
                    graph[neighbor]["I"].remove(key)
                del graph[key]
                break
        else:
            print("Impossible")
            break
    else:
        for i in range(ord("a"), ord("z") + 1):
            if chr(i) not in result:
                result += chr(i)
        print(result)