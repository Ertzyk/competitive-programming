t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    sum_even, sum_odd = 0, 0
    for i in range(0, len(a), 2):
        sum_even += a[i]
    for i in range(1, len(a), 2):
        sum_odd += a[i]
    print("NO" if sum_even%((len(a)+1)//2) or sum_odd%(len(a)//2) or sum_even//((len(a)+1)//2) != sum_odd//(len(a)//2) else "YES")