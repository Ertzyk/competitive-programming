import math
n = int(input())*2
print("YES" if math.floor(math.sqrt(n))**2+math.floor(math.sqrt(n)) == n else "NO")