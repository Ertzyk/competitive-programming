N = int(input())
a = list(map(int, input().split()))
bob, alice = a[-1], 0
for i in range(N - 2, -1, -1):
    if a[i] + alice > bob:
        bob, alice = a[i] + alice, bob
    else:
        alice += a[i]
print(alice, bob)