def operation1(lst):
    for i in range(0, len(lst), 2):
        lst[i], lst[i+1] = lst[i+1], lst[i]
    return lst

def operation2(lst):
    for i in range(len(lst)//2):
        lst[i], lst[i+len(lst)//2] = lst[i+len(lst)//2], lst[i]
    return lst

n = int(input())
p = list(map(int, input().split()))
if n%2:
    c, op, min_op_1, min_op_2 = p.copy(), 0, 0, 0
    while c[0] != 1:
        c, op = operation1(c) if op == 0 else operation2(c), (op + 1)%2
        min_op_1 += 1
    if c != [i + 1 for i in range(2*n)]:
        print(-1)
    else:
        c, op = p.copy(), 1
        while c[0] != 1:
            c, op = operation1(c) if op == 0 else operation2(c), (op + 1)%2
            min_op_2 += 1
        print(min(min_op_1, min_op_2))
else:
    c, k = p.copy(), 0
    for i in range(4):
        if c == [i + 1 for i in range(2*n)]:
            print(k if k < 3 else 1)
            break
        c = operation1(c) if i%2 else operation2(c)
        k += 1
    else:
        print(-1)