from decimal import Decimal, getcontext, ROUND_HALF_EVEN
getcontext().prec = 50 
n = int(input())
r = list(map(int, input().split()))
result = Decimal(0)
for i in range(n):
    for j in range(i + 1, n):
        if r[i] >= r[j]:
            result += Decimal(1) - Decimal(r[j] + 1) / Decimal(2 * r[i])
        else:
            result += Decimal(r[i] - 1) / Decimal(2 * r[j])
print(result.quantize(Decimal('0.000000'), rounding = ROUND_HALF_EVEN))