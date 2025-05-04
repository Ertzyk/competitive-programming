def left():
    l, r = 1, second_index - 1
    while l < r:
        m = (l + r + 1)//2
        print(f"? {m} {second_index}", flush = True)
        if int(input()) == second_index:
            l = m
        else:
            r = m - 1
    print(f"! {l}")

def right():
    l, r = second_index + 1, n
    while l < r:
        m = (l + r)//2
        print(f"? {second_index} {m}", flush = True)
        if int(input()) == second_index:
            r = m
        else:
            l = m + 1
    print(f"! {l}")

n = int(input())
print(f"? {1} {n}", flush = True)
second_index = int(input())
if second_index == 1:
    right()
else:
    print(f"? {1} {second_index}", flush = True)
    if int(input()) == second_index:
        left()
    else:
        right()