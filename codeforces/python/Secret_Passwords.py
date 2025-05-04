def set_to_string(my_set):
    res = ""
    for i in my_set:
        res += i
    return res

n = int(input())
components = set(())
for i in range(n):
    password = set(input())
    if password in components:
        continue
    new_component = password
    components_copy = components.copy()
    for j in components_copy:
        if set(j)&password:
            components.remove(j)
            new_component |= set(j)
    components.add(set_to_string(new_component))
print(len(components))