import math
l1, l2, l3 = list(map(int, input().split()))
print(l1**3*math.sqrt(2)/12 + l2**3*math.sqrt(2)/6 +l3**3/12*math.sqrt((5 + 2*math.sqrt(5))*(5 - math.sqrt(5))/2))