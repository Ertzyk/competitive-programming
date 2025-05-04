n, k = map(int, input().split())
both, alice, bob = [], [], []
for _ in range(n):
    t, a, b = map(int, input().split())
    if a == 1 and b == 1:
        both.append(t)
    elif a == 0 and b == 1:
        bob.append(t)
    elif a == 1 and b == 0:
        alice.append(t)
alice.sort()
bob.sort()
for i in range(min(len(alice), len(bob))):
    both.append(alice[i] + bob[i])
if len(both) < k:
    print(-1)
else:
    both.sort()
    print(sum(both[:k]))