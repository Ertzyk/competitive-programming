n = int(input())
x1, x2 = 0, 1023
for _ in range(n):
    operation, x = input().split()
    if operation == "&":
        x1 &= int(x)
        x2 &= int(x)
    elif operation == "|":
        x1 |= int(x)
        x2 |= int(x)
    else:
        x1 ^= int(x)
        x2 ^= int(x)
b0, b1, op1_num, op2_num, op3_num = bin(x1)[2:].zfill(10), bin(x2)[2:].zfill(10), "", "", ""
for i in range(10):
    if b0[i] == "0" and b1[i] == "1":
        op1_num += "1"
        op2_num += "0"
        op3_num += "0"
    elif b0[i] == "0" and b1[i] == "0":
        op1_num += "0"
        op2_num += "0"
        op3_num += "0"
    elif b0[i] == "1" and b1[i] == "1":
        op1_num += "1"
        op2_num += "1"
        op3_num += "0"
    else:
        op1_num += "1"
        op2_num += "0"
        op3_num += "1"
u1, u2, u3, short_program = int(op1_num, 2), int(op2_num, 2), int(op3_num, 2), []
if u1 != 1023:
    short_program.append("& " + str(u1))
if u2 != 0:
    short_program.append("| " + str(u2))
if u3 != 0:
    short_program.append("^ " + str(u3))
print(len(short_program))
if u1 != 1023:
    print("& " + str(int(op1_num, 2)))
if u2 != 0:
    print("| " + str(int(op2_num, 2)))
if u3 != 0:
    print("^ " + str(int(op3_num, 2)))