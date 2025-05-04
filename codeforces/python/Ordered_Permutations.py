for _ in range(int(input())):
    n, k = map(int, input().split())
    if k > 2**(n-1):
        print(-1)
    else:
        permutation, l, r, binary = [0] * n, 0, n - 1, bin(k - 1)[2:].zfill(n - 1)
        for i in range(1, n):
            if binary[i - 1] == "0":
                permutation[l] = i
                l += 1
            else:
                permutation[r] = i
                r -= 1
        permutation[l] = n
        print(*permutation)