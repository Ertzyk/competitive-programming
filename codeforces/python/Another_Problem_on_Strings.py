k = int(input())
s = input()
groups, count = [], 1
for i in s:
    if i == "1":
        groups.append(count)
        count = 1
    else:
        count += 1
groups.append(count)
pointer, result = 0, 0
if k > 0:
    while pointer + k < len(groups):
        result += groups[pointer]*groups[pointer + k]
        pointer += 1
else:
    for i in groups:
        result += i*(i - 1)//2
print(result)