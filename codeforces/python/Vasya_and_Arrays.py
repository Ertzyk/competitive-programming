len_A = int(input())
A = list(map(int, input().split()))
len_B = int(input())
B = list(map(int, input().split()))
k, l, a, b, s = A[0], B[0], 1, 1, 0

while True:
    if k > l:
        if b == len_B:
            print(-1)
            break
        l += B[b]
        b += 1
    elif k < l:
        if a == len_A:
            print(-1)
            break
        k += A[a]
        a += 1
    else:
        s += 1
        if a == len_A and b == len_B:
            print(s)
            break
        elif a == len_A or b == len_B:
            print(-1)
            break
        k, l = A[a], B[b]
        a += 1
        b += 1