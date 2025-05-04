input_file = open("input.txt", "r")
lines = input_file.readlines()
input_file.close()
N, M = map(int, lines[0].split())
K = int(lines[1])
b = list(map(int, lines[2].split()))
result = -1
for r in range(1, N + 1):
    for c in range(1, M + 1):
        cur_min = N + M
        for i in range(K):
            if abs(r - b[2*i]) + abs(c - b[2*i + 1]) < cur_min:
                cur_min = abs(r - b[2*i]) + abs(c - b[2*i + 1])
                if cur_min <= result:
                    break
        else:
            result = cur_min
            p, q = r, c
output_file = open("output.txt", "w")
output_file.writelines(f"{p} {q}")
output_file.close()