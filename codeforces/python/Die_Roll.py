w, y = list(map(int, input().split()))
if 6 - max(w, y) == 0:
    print("1/6")
elif 6 - max(w, y) == 1:
    print("1/3")
elif 6 - max(w, y) == 2:
    print("1/2")
elif 6 - max(w, y) == 3:
    print("2/3")
elif 6 - max(w, y) == 4:
    print("5/6")
else:
    print("1/1")