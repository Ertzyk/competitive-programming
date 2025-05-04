n, stowaway_pos, controller_pos = map(int, input().split())
controller_dir = -1 if input() == "to head" else 1
train_state = input()
second, stowaway_pos = 1, 1 if stowaway_pos < controller_pos else n
while second < len(train_state):
    if train_state[second - 1] == "1":
        stowaway_pos = n if controller_dir == -1 else 1
    controller_pos += controller_dir
    if controller_pos == 1:
        controller_dir = 1
    elif controller_pos == n:
        controller_dir = -1
    if controller_pos == stowaway_pos:
        print("Controller " + str(second))
        break
    second += 1
else:
    print("Stowaway")