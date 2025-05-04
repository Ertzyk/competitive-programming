a = list(map(int, input().split()))
b = list(map(int, input().split()))
if sum(a) > sum(b):
    print("Algosia")
elif sum(a) < sum(b):
    print("Bajtek")
else:
    a_bucket, b_bucket = [0]*11, [0]*11
    for i in a:
        a_bucket[10 - i] += 1
    for i in b:
        b_bucket[10 - i] += 1
    print("Algosia" if a_bucket > b_bucket else "Bajtek" if b_bucket > a_bucket else "remis")