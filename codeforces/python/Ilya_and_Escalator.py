import math

def bernolli(n, k, p):
    if n < k:
        return 0
    else:
        res, count_bi, temp = 1, 0, k
        if n - k > k:
            k = n - k
        for i in range(n):
            res *= p if i < temp else 1 - p
            if count_bi < n - k:
                res *= (k+1+i)/(i+1)
                count_bi += 1
        return res

n, p, t = input().split()
n, p, t, result, cur = int(n), float(p), int(t), 0, 0
for i in range(n):
    x = bernolli(t, i, p)
    print(x)
    print(math.comb(t, i)*p**i*(1-p)**(t-i))
    cur += x
    result += i*x
result += n*(1-cur)
print(result)