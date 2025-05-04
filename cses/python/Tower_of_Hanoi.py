def solve(a):
    if a == 1:
        return "2"
    x = solve(a - 1)
    return x.translate(str.maketrans("012345", "230154")) + "2" + x.translate(str.maketrans("012345", "104523"))
n = int(input())
solution = solve(n)
print(2**n-1)
for i in solution:
    if i == "0":
        print("1 2")
    elif i == "1":
        print("2 1")
    elif i == "2":
        print("1 3")
    elif i == "3":
        print("3 1")
    elif i == "4":
        print("2 3")
    else:
        print("3 2")