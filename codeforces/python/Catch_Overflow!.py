x, operations, multiplier, stack = 0, [], 1, []
for _ in range(int(input())):
    command = input()
    if command == "add":
        operations.append("add")
    elif command == "end":
        if operations[-1].isdigit():
            operations.pop()
        else:
            operations.append("end")
    else:
        operations.append(command.split()[1])
for operation in operations:
    if operation == "add":
        if x + multiplier < 2**32:
            x += multiplier
        else:
            print("OVERFLOW!!!")
            break
    elif operation == "end":
        multiplier //= int(stack.pop())
    else:
        multiplier *= int(operation)
        stack.append(operation)
        if multiplier + x >= 2**32:
            print("OVERFLOW!!!")
            break
else:
    print(x)